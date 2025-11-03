# Projet POO : Le Jeu de la Vie

## 1. Énoncé

Le **Jeu de la Vie** est un **automate cellulaire** imaginé par le mathématicien **John Conway**.
Il simule l’évolution d’une population de cellules sur un **temps discret**, selon des règles simples mais donnant lieu à des comportements complexes.

Les cellules sont disposées dans une **grille rectangulaire bidimensionnelle** et peuvent être dans deux états :

* **Vivantes (1)**
* **Mortes (0)**

À l’exclusion des bordures, le voisinage d’une cellule est constitué des **8 cellules directement adjacentes**.

### Règles de transition

À chaque itération `t → t+1`, l’état des cellules évolue selon les règles suivantes :

1. Une **cellule morte** possédant **exactement trois voisines vivantes** devient **vivante**.
2. Une **cellule vivante** possédant **deux ou trois voisines vivantes** reste **vivante**, sinon elle **meurt**.

L’objectif de ce projet est d’implémenter le Jeu de la Vie en **C++**, en utilisant les **concepts fondamentaux de la Programmation Orientée Objet (POO)**, en respectant les **principes SOLID**, et en produisant une version **console** puis une version **graphique avec SFML**.

---

## 2. Mode console : objectifs et attendus

Le mode console constitue la **base logique du programme**.
Il permet de vérifier le bon fonctionnement du moteur du jeu avant d’ajouter l’interface graphique.

Le programme doit lire un **fichier texte** dont :

* la **première ligne** indique la **taille de la grille** (nombre de lignes et de colonnes) ;
* les **lignes suivantes** décrivent l’état initial des cellules (`1` = vivante, `0` = morte).

### Exemple de fichier d’entrée

```
5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```

Après lecture du fichier, la grille est initialisée puis simulée selon les règles de Conway.

Le programme s’exécute pendant un **nombre d’itérations fixé en paramètre**, ou jusqu’à ce que le système **n’évolue plus** (état stable).
À chaque itération, la grille mise à jour est **enregistrée dans un fichier texte** au format d’entrée, dans un dossier :

```
<nom_du_fichier_dentree>_out/
```

Les fichiers générés suivent la convention :

```
iteration_001.txt
iteration_002.txt
iteration_003.txt
...
```

Un affichage console est recommandé, avec une représentation visuelle simple :

```
Itération : 4
Population : 9

..█.......
...█......
.███......
..........
..........
```

Le programme doit :

* gérer les erreurs de lecture (fichier manquant, dimensions invalides, valeurs incorrectes) ;
* assurer une **séparation claire entre la logique du jeu et les entrées/sorties** (aucune dépendance entre calcul et affichage) ;
* rester **performant pour des grilles moyennes** (jusqu’à 200×200).

---

## 3. Mode graphique avec SFML : objectifs et attendus

### Objectif du mode graphique

Le mode graphique doit permettre de **visualiser l’évolution de la grille en temps réel**, de **contrôler la simulation** (pause, reprise, vitesse, navigation), et d’**interagir avec les cellules** (édition, ajout de motifs).

L’interface sera développée avec **SFML (version 2.6.x)**.
Elle doit s’appuyer sur la même logique que le mode console : la partie graphique **n’ajoute pas de logique métier**, elle ne fait que représenter l’état du jeu.

### Boucle de rendu et synchronisation

* La simulation utilise un **pas de temps configurable** (en millisecondes par génération).
* Le **rendu** est **découplé de la logique** : on peut redessiner plus souvent que l’on ne met à jour la grille.
* Utiliser `sf::Clock` pour gérer la synchronisation.
* Cible de **60 FPS**, avec VSync autorisée.
* Complexité attendue : **O(N)** par génération (N = nombre total de cellules).

### Contrôles utilisateur par défaut

| Touche               | Action                               |
| -------------------- | ------------------------------------ |
| Espace               | Pause / Reprise                      |
| N                    | Avancer d’une génération (step)      |
| + / −                | Augmenter / Diminuer la vitesse      |
| R                    | Réinitialiser à l’état initial       |
| C                    | Effacer la grille (toutes mortes)    |
| G                    | Afficher / Masquer le quadrillage    |
| T                    | Activer / Désactiver le mode torique |
| S                    | Sauvegarder l’état courant           |
| L                    | Recharger un fichier d’état          |
| Clic gauche          | Basculer l’état d’une cellule        |
| Molette              | Zoom avant / arrière                 |
| Clic droit + glisser | Déplacer la vue (pan)                |

Un **overlay d’aide minimal** (ou section dans la console) doit rappeler ces commandes.

### Affichage demandé

* Fenêtre redimensionnable, titre explicite.
* Grille centrée, zoom/pan conservant les proportions.
* Couleurs configurables pour :

  * cellules vivantes, mortes et survolées,
  * quadrillage et fond.
* Overlay informatif en haut à gauche :

  * taille de la grille,
  * génération courante,
  * vitesse (ms/génération),
  * mode torique (on/off),
  * état de la simulation (pause ou en cours).
* Rendu optimisé via `sf::VertexArray` (quads) ou `sf::RenderTexture` pour les grandes grilles.

### Performance minimale attendue

* **200×200 cellules** simulées à **≥30 générations/seconde** sur une machine standard.
* Aucune saccade visible.
* Pas d’allocation mémoire récurrente dans la boucle principale (utiliser double buffer ou structures réutilisables).

### Gestion des fichiers

* Chargement initial via l’argument de ligne de commande :
  `--file=PATH`
* Sauvegarde au format texte identique à l’entrée :

  ```
  10 10
  0 1 0 0 0 1 0 0 1 0
  ...
  ```
* Le mode graphique sauvegarde uniquement **l’état courant** ; les sauvegardes itératives sont réservées au mode console.

### Paramètres en ligne de commande

```
--mode=console|gui     (par défaut gui)
--file=PATH            (chemin du fichier d’entrée, obligatoire)
--max-iters=N          (nombre d’itérations, console uniquement)
--step-ms=INT          (intervalle entre générations, en ms)
--cell-size=INT        (taille d’une cellule en pixels)
--toroidal=0|1         (mode torique)
--grid=0|1             (affichage du quadrillage)
```

En cas d’option invalide ou de fichier mal formé, le programme doit afficher un message clair et **ne pas planter**.

### Tests graphiques

Même si SFML ne se teste pas directement en unitaire, vous devez vérifier :

* la correspondance entre coordonnées écran et indices de cellule (clic souris),
* la cohérence du zoom/pan (pas de décalage après transformation),
* la stabilité de la vitesse configurée (mesurable par horloge logique).

### Extensions possibles (bonus)

* **Grille torique** (cellules des bords voisines des opposées).
* **Cellules obstacles** (fixes, vivantes ou mortes).
* **Palette de motifs préprogrammés** (glider, pulsar, etc.) insérables au clavier.
* **Éditeur de motifs** avec export/import de sous-grilles.
* **Coloration dynamique** selon l’ancienneté ou la densité locale.
* **Timeline interactive** avec navigation entre générations.
* **Parallélisation** du calcul de génération (threads).

---

## 4. Spécifications techniques

### Langage et environnement

* **Langage :** C++20 (C++17 accepté)
* **Bibliothèques :** STL et SFML 2.6.x
* **Outil de test :** [Catch2 v3](https://github.com/catchorg/Catch2)
* **OS cible de correction :** Linux 64-bit (Windows/macOS acceptés si build clair)
* **Industrialisation :**

  * Compilation via **Makefile**
  * Dockerfile permettant la **compilation et l’exécution console**
  * Build sans avertissement (`-Wall -Wextra -Wpedantic`)

---

## 5. Organisation du travail

* **Groupes de 4 étudiants maximum** (3 acceptés).
* **Utilisation obligatoire de Git** :

  * commits réguliers et explicites,
  * branche par fonctionnalité,
  * utilisation de **GitHub Issues** pour le suivi.
* Le dépôt Git doit contenir :

  * le code source,
  * un `README.md` complet (présentation, compilation, usage, exemples, captures),
  * un `ARCHITECTURE.md` (diagrammes UML, explications POO),
  * un `Makefile`,
  * le `Dockerfile` (build et exécution console),
  * des **fichiers d’entrée de test**.

---

## 6. Évaluation

L’évaluation portera sur les critères suivants :

* **Fonctionnalité** : respect des règles du jeu et exécution correcte.
* **Qualité du code** : lisibilité, cohérence, propreté, commentaires pertinents.
* **Programmation orientée objet** : encapsulation, héritage, polymorphisme, SOLID.
* **Robustesse** : gestion d’erreurs, stabilité, performance.
* **Architecture** : séparation logique / graphique, modularité du code.
* **Tests** : validité et exhaustivité des tests unitaires.
* **Outils de développement** : Git, Docker, Makefile, documentation.
* **Travail en équipe** : répartition du code et maîtrise du projet par tous les membres.

> Toute ressemblance entre codes, incapacité à expliquer le fonctionnement du programme ou tentative de plagiat sera sévèrement sanctionnée.

---

## 7. Diagrammes à produire

* Diagramme de **classes**
* Diagramme **d’activité**
* Diagramme de **séquence**

Ces diagrammes doivent figurer dans `ARCHITECTURE.md` et illustrer la conception objet du projet.

---

## 8. Livrables attendus

Le rendu final doit contenir :

```
/src             → code source complet
/include         → en-têtes
/tests           → tests Catch2
/examples        → fichiers d’entrée
/doc             → diagrammes UML et documentation
Makefile
Dockerfile
README.md
ARCHITECTURE.md
```

---

## 9. Objectif final

À l’issue du projet, vous devez disposer :

* d’une **implémentation complète, modulaire et robuste** du Jeu de la Vie,
* d’un **moteur de simulation réutilisable**,
* d’une **interface SFML fluide et interactive**,
* et d’un **projet industrialisé** (tests, Docker, documentation, Git, UML).

Le tout doit être **exécutable, reproductible et maintenable**.