# Mini-Projet C++ – Système Simplifié de Suivi de Projets et de Tâches

## Description générale du projet

Ce mini-projet consiste à développer un petit programme en C++ permettant de gérer un projet et les tâches qui le composent. Le programme sera utilisé dans un terminal.
Il devra permettre les actions suivantes : créer un projet, y ajouter des tâches, afficher ces tâches, et marquer certaines d’entre elles comme terminées.

L’objectif est d’apprendre à organiser un programme en plusieurs fichiers, manipuler des classes, utiliser un `std::vector`, compiler, tester progressivement, et structurer son travail avec GitHub Issues.

Le projet reste volontairement simple, adapté à des débutants. La priorité est la compréhension, la propreté du code et la progression étape par étape.

---

## Résumé des tâches attendues

Les éléments minimum à produire sont :

- Une classe `Tache` contenant un nom, une description, une priorité et un état (terminée ou non).
- Une classe `Projet` contenant un nom et une liste de tâches (un `std::vector<Tache>`).
- Des méthodes permettant d’ajouter une tâche, d’afficher les tâches et d’en marquer une comme terminée.
- Un programme principal (`main.cpp`) avec un menu texte simple.
- Une séparation propre en plusieurs fichiers `.hpp` (dans `includes/`) et `.cpp` (dans `src/`).
- L’utilisation de GitHub Issues pour suivre votre avancement.
- (Optionnel) Une dockerisation du projet.

---

## Partie 1 – Mise en place de l’environnement

1. Installer un éditeur ou IDE compatible C++.
2. Vérifier que vous pouvez compiler et exécuter un programme simple.

---

## Partie 2 – Création des classes

Les classes doivent être déclarées dans le dossier `include/` et implémentées dans le dossier `src/`.

### Classe `Tache`

Attributs recommandés :

- `std::string nom`
- `std::string description`
- une priorité (entier simple ou petit enum)
- un booléen indiquant si la tâche est terminée

Méthodes à prévoir :

- un constructeur
- une méthode pour terminer la tâche
- une méthode d’affichage (ex : `afficher()`)

### Classe `Projet`

Attributs recommandés :

- `std::string nom`
- `std::vector<Tache> taches`

Méthodes à prévoir :

- ajout d’une tâche
- affichage de toutes les tâches
- marquage d’une tâche comme terminée

---

## Partie 3 – Programme principal

Le fichier `main.cpp` doit présenter un menu console simple permettant :

1. Créer un projet
2. Ajouter une tâche
3. Afficher les tâches
4. Terminer une tâche
5. Quitter

Les entrées utilisateurs se feront avec `std::cin` et `std::cout`.

---

## Partie 4 – Bonnes pratiques

- Placer les .hpp dans `includes/` et les .cpp dans `src/`.
- Utiliser des noms clairs et cohérents.
- Commenter brièvement les classes.
- Compiler avec des options signalant les avertissements (`-Wall -Wextra`).
- Ne pas utiliser `new` ou `delete` (stockage direct dans les conteneurs).
- Garder un code simple, lisible, sans complexité inutile.

---

## Partie 5 – Travail avec GitHub Issues

Vous devez organiser votre projet avec GitHub Issues, comme dans un vrai petit projet logiciel.

### Liste d’exemples d’issues

La liste suivante est **non exhaustive**. Vous devez la compléter au cours du projet en créant d'autres issues à mesure que vous avancez.

- Issue : Créer la classe `Tache`
- Issue : Créer la classe `Projet`
- Issue : Ajouter un menu dans `main.cpp`
- Issue : Ajouter l’option “Ajouter une tâche”
- Issue : Ajouter l’option “Afficher les tâches”
- Issue : Ajouter l’option “Terminer une tâche”
- Issue : Ajouter des commentaires et nettoyer le code
- Issue : Finaliser le binaire
- Issue : Mise en place du README
- Issue (optionnelle) : Dockerisation

### Ce qui est attendu dans les GitHub Issues

Chaque issue doit contenir :

- un titre clair (ex : “Ajouter la classe Tache”),
- une description courte expliquant ce qui doit être fait,
- une checklist si nécessaire (ex : “Déclarer les attributs”, “Écrire le constructeur”…),
- un statut (ouverte / fermée),
- des issues supplémentaires créées dès qu’un besoin apparaît.

L’issue doit représenter une petite tâche réalisable facilement, afin de structurer votre travail.

Il n’est pas demandé d’utiliser des branches ni des pull requests : vous pouvez travailler directement sur le dépôt principal.

---

## Partie 6 (optionnelle) – Dockerisation du projet

Voici un exemple de `Dockerfile` minimal :

```Dockerfile
FROM gcc:latest
WORKDIR /app
COPY . .
RUN g++ -std=c++17 src/*.cpp -I include -o app
CMD ["./app"]
```

Pour tester :

```
docker build -t mini-projet-cpp .
docker run -it mini-projet-cpp
```

---

# Arborescence conseillée

```
mini-projet-cpp/
│
├── includes/
│   ├── Tache.hpp
│   ├── Projet.hpp
│
├── src/
│   ├── main.cpp
│   ├── Tache.cpp
│   ├── Projet.cpp
│
├── Dockerfile          (optionnel)
├── README.md
└── .gitignore
```
