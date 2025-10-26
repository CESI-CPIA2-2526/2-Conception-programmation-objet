# Introduction au C++

## Objectif du cours

Vous avez déjà programmé en Arduino et vous connaissez donc les bases : variables, conditions, boucles, fonctions…
Ce cours a pour but de vous apprendre à programmer en **C++ “pur”**, c’est-à-dire en dehors de l’environnement Arduino. Vous allez apprendre à écrire, compiler et exécuter un programme C++, puis à organiser votre code dans plusieurs fichiers.

Dans ce cours, nous suivrons un **exemple fil rouge** qui servira de support tout au long des explications. Cet exemple vous permettra de comprendre concrètement comment les éléments du langage C++ s’assemblent pour construire un programme complet.

À la fin du cours, un **mini-projet** vous sera proposé. Sa réalisation est **fortement recommandée**, car il vous permettra de consolider les notions abordées et de mettre en pratique ce que vous aurez appris.

Certaines notions, comme la **programmation orientée objet** (les classes et les objets), seront approfondies plus tard pendant les différents prostis. Il est donc **normal de ne pas tout assimiler immédiatement** : l’objectif est d’en avoir une première compréhension et de voir comment elles s’intègrent dans un vrai programme.

## Premier programme

Dans cette première partie, nous allons écrire et exécuter notre tout premier programme en C++.
L’objectif est de comprendre la structure de base d’un programme et le fonctionnement de la compilation.

Créez un nouveau fichier nommé **main.cpp**, puis copiez le code suivant :

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world !" << endl;
    return 0;
}
```

### Explications du code

* `#include <iostream>` : permet d’utiliser les entrées et sorties standard (affichage à l’écran, lecture au clavier).
* `using namespace std;` : autorise l’utilisation de `cout` sans devoir écrire `std::cout`.
* `int main()` : c’est le point d’entrée du programme, l’endroit où son exécution commence.
* `return 0;` : indique que le programme s’est terminé correctement.

### Compilation et exécution

Une fois le fichier enregistré, ouvrez un terminal (ou la console intégrée à votre IDE) dans le dossier contenant **main.cpp**, puis exécutez les commandes suivantes :

```bash
g++ main.cpp -o programme
./programme
```

La première commande **compile** le fichier source en langage machine et crée un exécutable nommé `programme`.
La seconde **lance** ce programme.

Si tout s’est bien déroulé, vous devriez voir apparaître dans le terminal :

```
Hello world !
```

### Comprendre ce qui se passe

Quand vous compilez un programme C++ :

1. Le **compilateur** traduit votre code en langage machine.
2. Le **linker** assemble ce code avec les bibliothèques nécessaires, comme celle des entrées/sorties (`iostream`).
3. Un **fichier exécutable** est créé.
4. Ce fichier peut ensuite être exécuté directement depuis le terminal.

Contrairement à l’environnement Arduino, où la compilation et l’exécution sont automatisées, le C++ “pur” demande de **compiler manuellement** votre code avant de pouvoir le lancer.
C’est ce qui vous donne plus de contrôle sur le processus et vous rapproche du fonctionnement réel des programmes utilisés dans le monde professionnel.

## Variables et types

Comme en Arduino, le C++ utilise des **types de variables** pour stocker différentes sortes de données.
Chaque variable doit être déclarée avec un type précis avant d’être utilisée.

Voici quelques exemples de types courants :

```cpp
int age = 20;                // nombre entier
float temperature = 23.5;    // nombre à virgule flottante
char lettre = 'A';           // caractère unique
bool estConnecte = true;     // valeur booléenne (vrai ou faux)
string nom = "Rohan";        // chaîne de caractères
```

Le C++ est un **langage typé statiquement**, ce qui signifie que le type de chaque variable est connu et vérifié au moment de la compilation.
Cela permet d’éviter de nombreuses erreurs, mais impose de déclarer correctement les types dès le départ.

Pour pouvoir utiliser le type `string`, vous devez inclure l’en-tête correspondant en haut de votre programme :

```cpp
#include <string>
```

Les types `int`, `float`, `char` et `bool`, eux, font partie du langage de base et ne nécessitent pas d’inclusion supplémentaire.


## Conditions et boucles

Les **structures de contrôle** permettent d’exécuter des blocs de code de manière conditionnelle ou répétée.
En C++, elles fonctionnent exactement comme en Arduino.

Voici quelques exemples classiques :

```cpp
for (int i = 0; i < 5; i++) {
    cout << "Compteur : " << i << endl;
}

int note = 15;
if (note >= 10) {
    cout << "Réussi !" << endl;
} else {
    cout << "Échec..." << endl;
}
```

### La structure conditionnelle `if`

Elle permet d’exécuter un bloc d’instructions uniquement si une condition est vraie.
L’ajout d’un `else` (et éventuellement `else if`) permet de gérer plusieurs cas possibles.

Exemple :

```cpp
int temperature = 18;

if (temperature > 25) {
    cout << "Il fait chaud." << endl;
} else if (temperature > 15) {
    cout << "Il fait bon." << endl;
} else {
    cout << "Il fait froid." << endl;
}
```

### Les boucles

#### La boucle `for`

Utilisée lorsque le **nombre d’itérations est connu** à l’avance.

```cpp
for (int i = 0; i < 10; i++) {
    cout << i << " ";
}
```

#### La boucle `while`

Utilisée lorsqu’on veut répéter une action **tant qu’une condition reste vraie**.

```cpp
int compteur = 0;
while (compteur < 3) {
    cout << "Boucle while : " << compteur << endl;
    compteur++;
}
```

#### La boucle `do...while`

Semblable à `while`, mais la condition est vérifiée **après** l’exécution du bloc, garantissant au moins une exécution.

```cpp
int nombre = 0;
do {
    cout << "Valeur : " << nombre << endl;
    nombre++;
} while (nombre < 3);
```

## Fonctions

Les fonctions permettent de **diviser un programme en plusieurs blocs logiques** pour mieux organiser le code et éviter les répétitions.
En C++, chaque fonction précise toujours le **type de valeur qu’elle renvoie** et les **paramètres qu’elle reçoit**.

Voici un exemple simple :

```cpp
int addition(int a, int b) {
    return a + b;
}

int main() {
    cout << "3 + 5 = " << addition(3, 5) << endl;
}
```

Ici :

* `int addition(int a, int b)` indique que la fonction renvoie un entier (`int`).
* `a` et `b` sont des **paramètres** transmis à la fonction.
* L’instruction `return a + b;` renvoie le résultat à l’endroit où la fonction a été appelée.

En C++, la fonction `main()` joue le rôle de point d’entrée du programme.
C’est elle qui est exécutée en premier, comme le ferait `setup()` puis `loop()` en Arduino.

### Fonctions qui ne renvoient rien

Il est aussi possible de créer des fonctions qui **ne renvoient aucune valeur**.
Dans ce cas, on utilise le mot-clé **`void`** comme type de retour.

Ces fonctions exécutent simplement une action sans fournir de résultat à récupérer.
Elles sont très fréquentes, par exemple pour afficher des messages ou modifier des variables globales.

Exemple :

```cpp
void afficherBienvenue() {
    cout << "Bienvenue dans le programme du robot !" << endl;
}

int main() {
    afficherBienvenue();
}
```

Ici, la fonction `afficherBienvenue()` ne retourne rien : elle se contente d’exécuter une instruction.
Il n’est donc pas nécessaire d’écrire `return`.

### Exemple fil rouge : gestion d’un robot

Dans ce cours, nous suivons un **fil rouge autour d’un petit robot**.
Ce robot pourra, au fil des sections, se déplacer, consommer de l’énergie et exécuter différentes actions.

Commençons par créer une fonction pour simuler un déplacement :

```cpp
void avancer(int distance) {
    cout << "Le robot avance de " << distance << " cm." << endl;
}

int main() {
    avancer(10);
    avancer(25);
}
```

La fonction `avancer()` est un bon exemple de fonction `void` : elle réalise une action (afficher un message) sans rien renvoyer.

### Exercice

Créez une fonction appelée `tourner()` qui affiche la direction du virage du robot.
La fonction prendra en paramètre un caractère (`'G'` pour gauche, `'D'` pour droite) et affichera le message correspondant.

Exemple attendu :

```
Le robot tourne à gauche.
Le robot tourne à droite.
```

Cet exercice vous aidera à manipuler les **paramètres de fonction** et à comprendre comment structurer le comportement de votre programme autour d’actions logiques.
Nous réutiliserons ces fonctions dans la suite du cours pour enrichir notre robot fil rouge.

## Tableaux et vecteurs

Les tableaux permettent de stocker plusieurs valeurs d’un même type sous un seul nom.
Cependant, en C++ moderne, on préfère utiliser la structure **`vector`**, plus souple et plus sûre que les tableaux statiques.

Un **tableau** classique doit avoir une taille fixée dès sa déclaration, par exemple :

```cpp
int notes[5] = {12, 14, 9, 16, 11};

for (int i = 0; i < 5; i++) {
    cout << notes[i] << endl;
}
```

Ici, le tableau `notes` contient exactement 5 éléments. Sa taille ne peut pas changer pendant l’exécution du programme.
Ce type de structure est rapide mais rigide.

---

### Les vecteurs (`vector`)

Les **vecteurs** fonctionnent comme des tableaux dynamiques : ils peuvent **s’agrandir ou se réduire automatiquement**.
Ils appartiennent à la bibliothèque standard du C++ et nécessitent l’inclusion de l’en-tête `<vector>`.

Exemple :

```cpp
#include <vector>
using namespace std;

int main() {
    vector<int> nombres = {1, 2, 3, 4, 5};
    nombres.push_back(6); // ajoute un élément à la fin du vecteur

    for (int n : nombres) {
        cout << n << " ";
    }
}
```

Le vecteur `nombres` contient ici les valeurs `{1, 2, 3, 4, 5, 6}`.
La méthode `push_back()` ajoute un nouvel élément à la fin du vecteur, sans qu’il soit nécessaire d’en redéfinir la taille.

Il est également possible d’accéder à un élément précis avec la même notation que pour un tableau :

```cpp
cout << "Premier élément : " << nombres[0] << endl;
```

---

### Exemple fil rouge : suivi de déplacements du robot

Reprenons notre robot fil rouge.
Nous souhaitons maintenant enregistrer la distance parcourue à chaque déplacement pour ensuite les afficher.

```cpp
#include <vector>
using namespace std;

void afficherDeplacements(vector<int> distances) {
    cout << "Historique des déplacements : ";
    for (int d : distances) {
        cout << d << "cm ";
    }
    cout << endl;
}

int main() {
    vector<int> distances;
    distances.push_back(10);
    distances.push_back(25);
    distances.push_back(15);

    afficherDeplacements(distances);
}
```

Ce programme crée un vecteur `distances` et y enregistre les valeurs des déplacements successifs du robot.
La fonction `afficherDeplacements()` parcourt ensuite le vecteur et affiche l’historique complet.

---

### Exercice

Créez un programme qui enregistre les **distances parcourues** par le robot au fur et à mesure de son déplacement.
Après chaque saisie (par exemple saisie clavier), ajoutez la distance au vecteur et affichez le total cumulé.

Exemple attendu :

```
Distance parcourue ? 10
Total : 10 cm
Distance parcourue ? 20
Total : 30 cm
Distance parcourue ? 15
Total : 45 cm
```

## Classes et objets

En Arduino, vous utilisez déjà des **objets** comme `Servo`, `Serial` ou `Wire`.
Ces objets sont issus de **classes**, c’est-à-dire des modèles qui définissent leurs propriétés et leurs comportements.
En C++, vous pouvez créer vos **propres classes** pour structurer vos programmes et représenter des entités du monde réel (un robot, un capteur, une voiture…).

Voici un premier exemple de classe simple :

```cpp
#include <iostream>
using namespace std;

class Robot {
private:
    string nom;
    int batterie;

public:
    Robot(string n, int b) {
        nom = n;
        batterie = b;
    }

    void avancer() {
        if (batterie > 0) {
            cout << nom << " avance !" << endl;
            batterie--;
        } else {
            cout << "Batterie vide." << endl;
        }
    }
};

int main() {
    Robot r1("R2D2", 3);
    r1.avancer();
    r1.avancer();
}
```

Ce programme crée une **classe `Robot`**, puis un **objet `r1`** basé sur ce modèle.
Le robot possède deux **attributs** (`nom` et `batterie`) et une **méthode** (`avancer()`).

---

### Détail du code

* **`private:`** signifie que les variables `nom` et `batterie` ne sont accessibles qu’à l’intérieur de la classe.
* **`public:`** indique que les fonctions peuvent être appelées depuis l’extérieur (dans le `main` par exemple).
* Le **constructeur** `Robot(string n, int b)` est une fonction spéciale qui s’exécute automatiquement lors de la création d’un objet.
* La méthode `avancer()` modifie la valeur de `batterie` et affiche un message selon son état.

Les classes permettent donc d’encapsuler les données (les attributs) et les comportements (les méthodes) dans une même structure, ce qui rend le code plus clair et réutilisable.

---

### Exemple fil rouge : un robot avec plusieurs actions

Nous allons poursuivre le développement de notre robot fil rouge en lui ajoutant plusieurs fonctionnalités.
Par exemple, il peut maintenant **avancer**, **tourner**, et **afficher son niveau de batterie** :

```cpp
#include <iostream>
using namespace std;

class Robot {
private:
    string nom;
    int batterie;

public:
    Robot(string n, int b) {
        nom = n;
        batterie = b;
    }

    void avancer(int distance) {
        if (batterie > 0) {
            cout << nom << " avance de " << distance << " cm." << endl;
            batterie--;
        } else {
            cout << "Batterie vide." << endl;
        }
    }

    void tourner(char direction) {
        if (batterie > 0) {
            if (direction == 'G')
                cout << nom << " tourne à gauche." << endl;
            else if (direction == 'D')
                cout << nom << " tourne à droite." << endl;
            batterie--;
        } else {
            cout << "Batterie vide." << endl;
        }
    }

    void afficherBatterie() {
        cout << "Niveau de batterie : " << batterie << endl;
    }
};

int main() {
    Robot r("EVA", 4);
    r.avancer(20);
    r.tourner('G');
    r.afficherBatterie();
}
```

Ici, le robot a plusieurs **méthodes publiques** lui permettant d’interagir avec son environnement.
Chaque action consomme de la batterie, simulant un comportement réaliste.

---

### Exercice

Complétez la classe `Robot` en ajoutant une méthode `recharger()` qui remet la batterie à son niveau maximum (par exemple 5).
Testez-la dans le `main()` en vidant d’abord la batterie avec plusieurs appels à `avancer()`, puis en appelant `recharger()`.

Exemple attendu :

```
EVA avance de 20 cm.
EVA tourne à gauche.
Batterie vide.
EVA est rechargé.
Niveau de batterie : 5
```

## Organisation du code : fichiers .h et .cpp

Jusqu’à présent, tout notre code était contenu dans un seul fichier.
Mais à mesure qu’un programme grandit, il devient nécessaire de **mieux organiser le code** pour le rendre plus lisible et plus facile à maintenir.

En C++, il est courant de séparer :

* les **déclarations** (dans un fichier `.h`, appelé *header*),
* et les **implémentations** (dans un fichier `.cpp`).

Cette structure permet de mieux organiser les classes et d’éviter de surcharger le fichier principal.

---

### Exemple : découpage d’une classe `Robot`

**Robot.h**

```cpp
#ifndef ROBOT_H
#define ROBOT_H

#include <string>
using namespace std;

class Robot {
private:
    string nom;
    int batterie;

public:
    Robot(string n, int b);
    void avancer();
};

#endif
```

Ce fichier contient uniquement la **déclaration** de la classe : les noms des attributs et des méthodes, mais pas leur contenu.
La structure `#ifndef`, `#define`, `#endif` empêche que le fichier soit inclus plusieurs fois par erreur.

---

**Robot.cpp**

```cpp
#include "Robot.h"
#include <iostream>
using namespace std;

Robot::Robot(string n, int b) : nom(n), batterie(b) {}

void Robot::avancer() {
    if (batterie > 0)
        cout << nom << " avance !" << endl;
    else
        cout << "Batterie vide." << endl;
}
```

Ce fichier contient l’**implémentation** des fonctions de la classe.
Chaque fonction est précédée du nom de la classe suivi de `::` (appelé *opérateur de résolution de portée*) pour indiquer qu’elle appartient à cette classe.

---

**main.cpp**

```cpp
#include "Robot.h"

int main() {
    Robot r("Wall-E", 2);
    r.avancer();
}
```

Le fichier principal ne contient plus que le code qui fait tourner le programme.
Il “importe” la classe `Robot` grâce à l’instruction `#include "Robot.h"`.

---

### Compilation d’un projet multi-fichiers

Pour compiler un projet composé de plusieurs fichiers, il faut préciser au compilateur tous les fichiers sources `.cpp` à inclure :

```bash
g++ main.cpp Robot.cpp -o robot
./robot
```

Le compilateur va d’abord traduire chaque fichier `.cpp` en langage machine, puis **lier** le tout en un exécutable unique.

---

### Exemple fil rouge : extension du robot

Nous pouvons maintenant ajouter de nouvelles méthodes dans la classe `Robot` sans alourdir le fichier principal.
Par exemple, une méthode `afficherEtat()` :

**Robot.h**

```cpp
void afficherEtat();
```

**Robot.cpp**

```cpp
void Robot::afficherEtat() {
    cout << "Nom : " << nom << ", Batterie : " << batterie << endl;
}
```

**main.cpp**

```cpp
#include "Robot.h"

int main() {
    Robot r("EVA", 3);
    r.avancer();
    r.afficherEtat();
}
```

Ce découpage permet d’organiser les fonctionnalités du robot dans des fichiers dédiés, tout en gardant un code clair et facile à lire.

---

### Exercice

Réorganisez le programme du robot fil rouge en séparant correctement la **déclaration** et l’**implémentation**.
Ajoutez ensuite une méthode `tourner()` dans `Robot.h` et son code dans `Robot.cpp`, puis testez-la dans `main.cpp`.

Vous devez pouvoir compiler le tout avec la commande suivante :

```bash
g++ main.cpp Robot.cpp -o robot
./robot
```

## Conclusion du cours : explication du mini-projet

Pour conclure ce cours, nous allons résumer tout ce que nous avons appris à travers un **mini-projet complet** : la création d’un **robot autonome**.
Ce projet reprend pas à pas les notions abordées — variables, fonctions, vecteurs, classes, organisation du code — et les met en pratique dans un programme cohérent.

L’objectif est de **manipuler du vrai code C++**, de comprendre sa structure et de tester le comportement du programme par vous-même.
Prenez le temps d’expérimenter, de modifier les valeurs et d’ajouter des idées : c’est la meilleure façon de progresser.

### 1. Organisation du projet

Le projet est structuré en trois fichiers :

* **`Robot.h`** : déclaration de la classe (ce qu’elle contient et ce qu’elle peut faire)
* **`Robot.cpp`** : définition du comportement des fonctions de la classe
* **`main.cpp`** : point d’entrée du programme, où vous testez votre robot

### 2. Fichier `Robot.h`

```cpp
#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <vector>
using namespace std;

// Définition de la classe Robot
class Robot {
private:
    string nom;                 // nom du robot
    int batterie;               // niveau de batterie
    vector<int> deplacements;   // historique des distances parcourues

public:
    // Constructeur : initialise un robot avec un nom et une batterie
    Robot(string n, int b);

    // Méthode pour avancer sur une certaine distance
    void avancer(int distance);

    // Méthode pour tourner à gauche ou à droite
    void tourner(char direction);

    // Recharge complètement la batterie
    void recharger();

    // Affiche l'état complet du robot
    void afficherEtat();
};

#endif
```

### 3. Fichier `Robot.cpp`

```cpp
#include "Robot.h"
#include <iostream>
using namespace std;

// Constructeur : initialise les attributs du robot
Robot::Robot(string n, int b) : nom(n), batterie(b) {}

// Fait avancer le robot d'une certaine distance
void Robot::avancer(int distance) {
    if (batterie > 0) {
        cout << nom << " avance de " << distance << " cm." << endl;
        batterie--;                     // chaque déplacement consomme de la batterie
        deplacements.push_back(distance); // on enregistre la distance parcourue
    } else {
        cout << "Batterie vide, impossible d'avancer." << endl;
    }
}

// Fait tourner le robot à gauche ('G') ou à droite ('D')
void Robot::tourner(char direction) {
    if (batterie > 0) {
        if (direction == 'G')
            cout << nom << " tourne à gauche." << endl;
        else if (direction == 'D')
            cout << nom << " tourne à droite." << endl;
        else
            cout << "Commande invalide." << endl;
        batterie--; // tourner consomme aussi un peu de batterie
    } else {
        cout << "Batterie vide, impossible de tourner." << endl;
    }
}

// Recharge la batterie du robot
void Robot::recharger() {
    batterie = 5;
    cout << nom << " est rechargé à 100%." << endl;
}

// Affiche un résumé complet de l'état du robot
void Robot::afficherEtat() {
    cout << "\n=== ÉTAT DU ROBOT ===" << endl;
    cout << "Nom : " << nom << endl;
    cout << "Batterie restante : " << batterie << endl;

    cout << "Historique des déplacements : ";
    if (deplacements.empty()) {
        cout << "Aucun déplacement enregistré." << endl;
    } else {
        for (int d : deplacements)
            cout << d << "cm ";
        cout << endl;
    }

    cout << "======================" << endl;
}
```

### 4. Fichier `main.cpp`

```cpp
#include "Robot.h"

int main() {
    // Création d'un robot nommé EVA avec 3 unités de batterie
    Robot r("EVA", 3);

    // Le robot effectue différentes actions
    r.avancer(20);       // avance de 20 cm
    r.tourner('G');      // tourne à gauche
    r.avancer(15);       // avance de 15 cm
    r.afficherEtat();    // affiche l'état actuel (batterie et déplacements)

    // Batterie bientôt vide, on recharge
    r.recharger();
    r.avancer(30);
    r.afficherEtat();

    return 0;
}
```

### 5. Compilation et exécution

Dans le terminal, compilez l’ensemble du projet :

```bash
g++ main.cpp Robot.cpp -o robot
./robot
```

Vous devriez voir un résultat proche de ceci :

```
EVA avance de 20 cm.
EVA tourne à gauche.
EVA avance de 15 cm.

=== ÉTAT DU ROBOT ===
Nom : EVA
Batterie restante : 0
Historique des déplacements : 20cm 15cm
======================

EVA est rechargé à 100%.
EVA avance de 30 cm.

=== ÉTAT DU ROBOT ===
Nom : EVA
Batterie restante : 4
Historique des déplacements : 20cm 15cm 30cm
======================
```