# Tuto : Ajouter des tests unitaires au "Jeu de la Vie" (Visual Studio)

## Point de vigilance crucial avant de commencer

Pour que les tests fonctionnent, il y a une seule règle d'or technique :
**Le fichier qui contient votre `int main()` ne doit pas être inclus dans les tests.**

Pourquoi ? Parce que Google Test possède son propre `main()`. Si vous incluez votre `main.cpp` dans les tests, Visual Studio ne saura pas lequel lancer et la compilation échouera.

**La solution simple :**
Vos fonctions de calcul (ex: `compterVoisins`, `calculerGeneration`) doivent être dans un fichier `.cpp` à part (ex: `simulation.cpp` ou `fonctions.cpp`), séparé du fichier qui lance le programme.

-----

## Étape 1 : Préparer le dossier de tests

Dans votre dossier projet (à côté de `src` et `CMakeLists.txt`), créez simplement un dossier `tests` et un fichier vide `tests/test_unitaire.cpp`.

Votre structure doit ressembler à ceci :

```text
ProjetJeuDeLaVie/
├── CMakeLists.txt       <-- On va le modifier légèrement
├── src/
│   ├── main.cpp         <-- Contient le main() (Lancement du jeu)
│   ├── simulation.cpp   <-- Contient vos fonctions (Logique du jeu)
│   └── simulation.hpp   <-- Les déclarations
└── tests/
    └── test_unitaire.cpp <-- Votre nouveau fichier de test
```

-----

## Étape 2 : Configurer CMake (Le chef d'orchestre)

Ouvrez votre `CMakeLists.txt` existant.
Vous avez déjà une partie qui gère votre jeu. **Ne la touchez pas.**
Ajoutez simplement ce bloc à la toute fin du fichier.

```cmake
# --- VOTRE FICHIER EXISTANT (Ne touchez pas au début du fichier) ---

# --- AJOUT DES TESTS (À coller à la fin du fichier) ---

# 1. Télécharger Google Test automatiquement
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Astuce pour Windows : évite les conflits de DLL
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. Créer l'exécutable de test
# IMPORTANT : Mettez ici vos fichiers .cpp de logique (simulation.cpp)
# MAIS SURTOUT PAS le fichier qui contient le main() (main.cpp) !
add_executable(RunTests 
    tests/test_unitaire.cpp 
    src/simulation.cpp 
)

# 3. Lier Google Test
target_link_libraries(RunTests GTest::gtest_main)

# 4. Activer la détection dans Visual Studio
include(GoogleTest)
gtest_discover_tests(RunTests)
```

-----

## Étape 3 : Écrire un premier test

Dans `tests/test_unitaire.cpp`, vous allez simplement appeler vos fonctions existantes.

Exemple pour le Jeu de la Vie (à adapter suivant votre code mais pour vous donner une idée).

```cpp
#include <gtest/gtest.h>
#include "../src/simulation.hpp" // On inclut vos fonctions (à adapter suivant votre architecture)

// Test simple : Vérifier qu'une cellule isolée meurt (Règle 1)
TEST(TestRegles, CelluleIsoleeMeurt) {
    // 1. Initialisation (Setup)
    // Imaginez que vous ayez une grille ou une fonction pour configurer
    std::vector<std::vector<int>> grille(10, std::vector<int>(10, 0));
    
    // On place une cellule vivante (1) sans voisins
    grille[5][5] = 1;

    // 2. Action (On appelle VOTRE fonction de calcul)
    int voisins = compterVoisins(grille, 5, 5); // Supposons que cette fonction existe

    // 3. Vérification (Assert)
    // Une cellule isolée a 0 voisin, donc elle doit mourir au prochain tour
    // Si votre fonction retourne 0, le test passe.
    EXPECT_EQ(voisins, 0); 
}

// Test : Vérifier qu'une cellule avec 3 voisins nait (Règle 3)
TEST(TestRegles, NaissanceCellule) {
    std::vector<std::vector<int>> grille(10, std::vector<int>(10, 0));
    
    // On place 3 voisins autour de (5,5)
    grille[5][4] = 1;
    grille[4][5] = 1;
    grille[6][5] = 1;

    int voisins = compterVoisins(grille, 5, 5);
    
    // S'il y a 3 voisins, la règle de naissance s'applique
    EXPECT_EQ(voisins, 3);
}
```

-----

## Étape 4 : Lancer dans Visual Studio

1.  **Sauvegardez** le `CMakeLists.txt`.
2.  Regardez la fenêtre **Sortie** (Output) en bas. Visual Studio va reconfigurer le projet (ça peut prendre 1 minute pour télécharger GTest).
3.  Allez dans le menu **Test \> Explorateur de tests** (Test Explorer).
4.  Si la fenêtre est vide, cliquez sur le bouton "Exécuter tout" (le petit triangle vert) pour forcer la compilation.
5.  Vos tests `TestRegles` vont apparaître.

### Si ça ne compile pas (Erreur fréquente)

Si vous avez une erreur du type `LNK2005 : main already defined`, c'est que vous avez laissé `src/main.cpp` dans la liste des fichiers de `add_executable(RunTests ...)` dans le CMake. Enlevez-le, et ça marchera.
