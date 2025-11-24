# Projet C++ / POO : Le Jeu de la Vie

## 1\. Énoncé

Le **Jeu de la Vie** est un automate cellulaire imaginé par le mathématicien **John Conway**. Il simule l’évolution d’une population de cellules sur un temps discret, selon des règles simples donnant lieu à des comportements complexes.

Les cellules sont disposées dans une grille rectangulaire bidimensionnelle et peuvent être dans deux états :

- **Vivantes (1)**
- **Mortes (0)**

Le voisinage d’une cellule est constitué des **8 cellules directement adjacentes**.

### Règles de transition

À chaque itération `t → t+1`, l’état des cellules évolue selon les règles suivantes :

1.  Une **cellule morte** possédant **exactement trois voisines vivantes** devient **vivante**.
2.  Une **cellule vivante** possédant **deux ou trois voisines vivantes** reste **vivante**, sinon elle **meurt** (sous-population ou surpopulation).

L’objectif est d’implémenter ce jeu en **C++**, en utilisant les concepts fondamentaux de la **POO**, en respectant les principes **SOLID**, et en produisant une version **console** puis une version **graphique avec SFML**.

## 2\. Mode Console : Le Moteur Logique

Le mode console constitue le cœur du programme. Il doit garantir une séparation stricte entre la **logique métier** (la grille, les règles) et l'**interface** (affichage, fichiers).

Le programme lit un fichier texte décrivant l'état initial :

- Ligne 1 : Dimensions (Lignes Colonnes)
- Lignes suivantes : État des cellules (`1` ou `0`)

### Exemple de fichier d’entrée (`input.txt`)

```text
5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```

### Fonctionnement

Le programme s’exécute pendant un nombre d’itérations fixé ou jusqu’à stabilisation.
À chaque itération, la grille est **enregistrée dans un fichier texte** dans un dossier dédié (`input_out/iteration_XXX.txt`).

Un affichage console simplifié est attendu pour le suivi :

```text
Itération : 4 | Population : 9
..█.......
...█......
.███......
```

**Contraintes techniques console :**

- Gestion robuste des erreurs (fichiers, dimensions).
- Aucune dépendance de la classe "Grille" vers "iostream" (utiliser des flux ou des interfaces).
- Performance acceptable pour des grilles moyennes (200×200).

## 3\. Mode Graphique (SFML) : Visualisation & Interaction

L'interface graphique (SFML 2.6.x) permet de visualiser l'évolution en temps réel. Elle ne doit contenir **aucune logique métier**, mais seulement représenter l'état du moteur.

### Boucle de rendu et Performance

- **Cible :** 60 FPS (VSync active).
- **Optimisation critique :** L'utilisation de `sf::RectangleShape` pour chaque cellule est **interdite** pour les grilles \> 50x50 (trop lent). Vous devez utiliser un **`sf::VertexArray`** (Quads) ou une `sf::RenderTexture`.
- **Complexité :** O(N) par génération.
- **Mémoire :** Aucune allocation dynamique (`new`) dans la boucle principale de rendu.

### Contrôles utilisateur

| Touche          | Action                                                 |
| :-------------- | :----------------------------------------------------- |
| **Espace**      | Pause / Reprise                                        |
| **N**           | Avancer d’une génération (Step-by-step)                |
| **+ / −**       | Augmenter / Diminuer la vitesse de simulation          |
| **R**           | Réinitialiser à l’état initial (fichier source)        |
| **C**           | Clear (tuer toutes les cellules)                       |
| **G**           | Afficher / Masquer la grille                           |
| **S**           | Sauvegarder l’état courant (fichier texte)             |
| **T**           | Activer / Désactiver le mode torique _(si implémenté)_ |
| **Clic Gauche** | Ressusciter / Tuer une cellule                         |
| **Molette**     | Zoom Avant / Arrière                                   |
| **Clic Droit**  | Pan (Déplacer la caméra)                               |

### Interface (HUD)

Un overlay (texte simple) en haut à gauche doit afficher :

- État (En cours / Pause)
- Génération actuelle & Population
- Vitesse (ms par génération)
- Mode (Torique : ON/OFF)

## 4\. Spécifications Techniques & Outils

- **Langage :** C++20 (C++17 accepté).
- **Build System :** Makefile obligatoire.
- **Qualité du code :**
  - Respect d'un style de code via un fichier `.clang-format` fourni.
  - Compilation sans avertissement : `-Wall -Wextra -Wpedantic`.
- **Tests :** Framework [Catch2 v3](https://github.com/catchorg/Catch2) pour tester la logique (règles, chargement fichiers).
- **CI/CD :** Dockerfile permettant la compilation et l'exécution du mode console.

## 5\. Organisation et Rendu

- **Équipe :** 3 à 4 étudiants.
- **Gestion de version :** Git obligatoire (commits atomiques, branches par feature).

### Livrables attendus

Le dépôt doit être propre et structuré :

1.  `/src` et `/include` : Code source.
2.  `/tests` : Tests unitaires Catch2.
3.  `Makefile` : Cibles `all`, `console`, `gui`, `tests`, `clean`.
4.  `Dockerfile` : Environnement de build/run console.
5.  `.clang-format` : Fichier de configuration de style.
6.  `Doxyfile` : Configuration pour générer la documentation HTML du code.
7.  `README.md` : Compilation, usage, captures d'écran.
8.  `ARCHITECTURE.md` :
    - **Diagramme de Classes** (UML).
    - **Diagramme de Séquence** (Boucle principale du jeu).
    - **Diagramme d’États-Transitions** (Cycle de vie : Menu -\> Run -\> Pause -\> Edit).
9.  `PERFORMANCE.md (Optionnel)` : 
    - Analyse des performances (complexité, mémoire).
    - Justification des choix d’implémentation.
    - Résultats de tests de performance (grilles 100x100, 200x200).

## 6\. Soutenance et Évaluation (30 min)

La note prendra en compte la fonctionnalité, la qualité POO (SOLID), la propreté du code et l'outillage.

### Déroulé de la soutenance

1.  **Architecture & Choix (10 min) :**
    - Présentation des diagrammes UML.
    - Justification des choix mémoire et performance (pourquoi ce conteneur ?).
    - Explication de la séparation Modèle-Vue.
2.  **Démonstration (10 min) :**
    - Scénarios nominaux et cas limites (fichiers corrompus, grille vide).
3.  **Le "Défi Live" (5 min) :**
    - Le jury vous demandera une **modification du code en direct** (ex: changement d'une règle de naissance, ajout d'une interaction simple).
    - _Objectif :_ Vérifier que votre code est **modulaire** et **extensible** (Open/Closed Principle). Si votre architecture est propre, cela ne prendra que quelques lignes.
4.  **Questions / Réponses (5 min).**

### Extensions (Bonus)

- **Mode Torique :** Les bords sont connectés (la droite touche la gauche, le haut touche le bas).
- **Historique :** Possibilité de revenir en arrière (Ctrl+Z).
- **Éditeur de motifs :** Insertion de structures connues (Glider, Pulsar) via des touches ou un menu.
