# Guide : Outils de Qualité de Code (VS & Doxygen)

Ce document explique comment configurer votre environnement pour respecter les standards du projet : **formatage automatique** et **documentation**.

-----

## PARTIE 1 : Formatage automatique (Clang-Format)

Pour garantir un code propre et respecter les normes du projet sans effort, nous utilisons un fichier de configuration standard.

### Étape 1 : Placement du fichier

1.  Prenez le fichier `.clang-format` fourni.
2.  Copiez-le **à la racine de votre Solution** (c'est-à-dire dans le même dossier que votre fichier `.sln`).

### Étape 2 : Activation dans Visual Studio

Visual Studio détecte automatiquement ce fichier, mais il faut s'assurer que l'option est active :

1.  Lancez Visual Studio.

2.  Allez dans le menu **Outils** \> **Options** (`Tools > Options`).

3.  Déroulez : **Éditeur de texte** \> **C/C++** \> **Mise en forme** (`Text Editor > C/C++ > Formatting`).

4.  Cochez la case **"Activer la prise en charge de ClangFormat"** (`Enable ClangFormat support`).

5.  Cliquez sur **OK**.

### Étape 3 : Utilisation

- **Formatage manuel :**
      Ouvrez un fichier `.cpp` ou `.h` et faites le raccourci : **`Ctrl + K`**, puis **`Ctrl + D`**.
      *Cela reformatera tout le document selon les règles du fichier `.clang-format`.*

- **Formatage automatique à la sauvegarde (Optionnel mais recommandé) :**
      *Si vous avez Visual Studio 2022 :*
      1.  Allez dans **Analyser** \> **Nettoyage du code** \> **Configurer le nettoyage du code**.
      2.  Créez un profil (ou modifiez le profil 1) et ajoutez "Formater le document" dans la liste du bas.
      3.  Ensuite, allez dans **Outils** \> **Options** \> **Éditeur de texte** \> **Nettoyage du code**.
      4.  Cochez **"Exécuter le nettoyage du code lors de l'enregistrement"**.

> **Rappel important :** L'outil gère les espaces et les accolades. C'est à **vous** de respecter le nommage (variables en `camelCase`, classes en `PascalCase`) et d'écrire la documentation Doxygen comme indiqué ci-dessous.

-----

## PARTIE 2 : Documentation (Doxygen)

Doxygen permet de générer un site web qui décrit vos classes et méthodes. C'est le standard industriel pour la documentation technique.

### Étape 1 : Installation

1. Téléchargez et installez **Doxygen** depuis le site officiel (version Windows binaries).
2. *(Optionnel mais conseillé)* Installez **Graphviz** si vous voulez que Doxygen génère les diagrammes de classes UML automatiquement.

### Étape 2 : Commenter le code dans Visual Studio

Visual Studio possède une fonction géniale pour vous aider.
Juste au-dessus d'une fonction ou d'une classe, tapez trois fois sur slash : `///`.

Visual Studio va générer automatiquement le squelette du commentaire :

```cpp
/// <summary>
/// 
/// </summary>
/// <param name="grid"></param>
/// <returns></returns>
Grid evolve(const Grid& grid);
```

**Votre travail** est de remplir les trous. Pour que ce soit compatible avec le format standard Doxygen demandé, vous pouvez aussi utiliser le format `@param` :

```cpp
/// Calcule la prochaine génération de cellules.
/// @param grid La grille actuelle en lecture seule.
/// @return Une nouvelle grille contenant l'état t+1.
Grid evolve(const Grid& grid);
```

### Étape 3 : Configurer et Générer la doc

Pas besoin de ligne de commande, utilisez l'interface graphique **Doxywizard** installée avec Doxygen.

1. Lancez **Doxywizard**.

2. **Section "Wizard" (Assistant) :**

      - **Project name :** "Jeu de la Vie".
      - **Source code directory :** Sélectionnez le dossier contenant vos `.cpp` et `.hpp`.
      - **Destination directory :** Créez un dossier `/doc` à la racine de votre projet.
      - **Scan recursively :** Cochez la case (pour qu'il cherche dans les sous-dossiers `src` et `include`).

3. **Section "Mode" :**

      - Choisissez "All Entities" (pour tout documenter, même les fonctions privées si besoin).
      - Sélectionnez le langage **C++**.

4. **Sauvegarde :**

      - File \> **Save**. Enregistrez le fichier sous le nom `Doxyfile` à la racine de votre projet.
      - **Important :** Ce fichier `Doxyfile` doit être ajouté à votre Git \!

5. **Génération :**

      - Allez dans l'onglet **"Run"** et cliquez sur "Run doxygen".
      - Ouvrez le fichier `doc/html/index.html` pour admirer le résultat \!

> **Astuce Git :** N'ajoutez **PAS** le dossier `doc/html` (le site généré) sur Git. Ajoutez uniquement le fichier de configuration `Doxyfile`. Chacun peut régénérer la doc chez soi.
> Ajoutez `doc/` ou `doc/html/` à votre `.gitignore`.
