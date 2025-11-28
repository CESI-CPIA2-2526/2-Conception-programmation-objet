# Introduction à la SFML : Les Bases

### Prérequis

  * Des connaissances de base en C++ (variables, boucles, classes).
  * Un environnement de développement (Visual Studio, VS Code, CLion, etc.) avec la **SFML installée et liée** à votre projet.

## 1\. Le Concept Fondamental : La "Game Loop"

Contrairement à un programme console qui s'exécute de haut en bas et s'arrête, une application graphique tourne en boucle infinie. C'est ce qu'on appelle la **Boucle Principale** (Game Loop).

Elle fait trois choses en permanence, 60 fois par seconde (ou plus) :

1.  **Gérer les évènements** (clavier, souris).
2.  **Mettre à jour la logique** (déplacer un personnage).
3.  **Afficher le rendu** (dessiner l'image).

## 2\. Créer sa première fenêtre

Pour commencer, nous avons besoin d'inclure le module graphique.

```cpp
#include <SFML/Graphics.hpp>

int main()
{
    // 1. Création de la fenêtre
    // Arguments : Largeur, Hauteur, "Titre de la fenêtre"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mon Cours SFML");

    // Limiter les FPS à 60 pour ne pas surchauffer le processeur
    window.setFramerateLimit(60);

    // 2. La Boucle Principale
    while (window.isOpen())
    {
        // A. GESTION DES ÉVÈNEMENTS (Voir section suivante)
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // B. AFFICHAGE (Le cycle sacré : Effacer -> Dessiner -> Afficher)
        window.clear(sf::Color::Black); // 1. On efface tout (en noir)
        
        // ... Ici on dessinera nos objets ...

        window.display(); // 2. On affiche le résultat à l'écran
    }

    return 0;
}
```

> **Note importante :** Si vous oubliez `window.display()`, votre fenêtre restera noire. Si vous oubliez `window.clear()`, les images précédentes resteront affichées (effet de "trace").


## 3\. Le Système de Coordonnées

En programmation graphique, le repère est différent des mathématiques classiques.

  * **L'origine (0, 0)** est en haut à gauche.
  * **L'axe X** va vers la droite.
  * **L'axe Y** va vers le bas.

## 4\. Dessiner des formes

La SFML propose des formes simples prêtes à l'emploi : `sf::CircleShape`, `sf::RectangleShape`, etc.

Ajoutons un cercle vert à notre programme. On doit le déclarer **avant** la boucle principale (pour ne pas le recréer à chaque image).

```cpp
// ... avant le while(window.isOpen()) ...

sf::CircleShape shape(50.f); // Rayon de 50 pixels
shape.setFillColor(sf::Color::Green); // Couleur de remplissage
shape.setPosition(100.f, 100.f); // Position (X, Y)

// ... dans la boucle, entre clear() et display() ...

window.draw(shape);
```

### Propriétés utiles des formes :

  * `setFillColor(sf::Color::Red)` : Changer la couleur.
  * `setOutlineThickness(5.f)` : Ajouter une bordure.
  * `setOutlineColor(sf::Color::White)` : Couleur de la bordure.
  * `move(x, y)` : Déplacer la forme relativement à sa position actuelle.

## 5\. L'Animation et le Temps (`sf::Clock`)

Si vous dites à votre forme d'avancer de "+1 pixel" à chaque tour de boucle, la vitesse de l'animation dépendra de la puissance de l'ordinateur. C'est une mauvaise pratique.

Pour une animation fluide et constante, on utilise le **Temps (Delta Time)**. On demande à la SFML : *"Combien de temps s'est écoulé depuis la dernière image ?"*.

```cpp
sf::Clock clock; // On lance un chronomètre

while (window.isOpen())
{
    // On récupère le temps écoulé et on redémarre le chrono
    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds(); // Delta Time en secondes (ex: 0.016s)

    // ... Gestion des évènements ...

    // Mise à jour logique :
    // On veut bouger de 100 pixels par seconde vers la droite
    // Vitesse * Temps = Distance
    shape.move(100.f * dt, 0.f); 

    // ... Affichage ...
}
```

## 6\. Code Complet et Commenté

Voici le code final qui ouvre une fenêtre, affiche un cercle et le fait bouger fluidement vers la droite, tout en permettant de fermer la fenêtre.

```cpp
#include <SFML/Graphics.hpp>

int main()
{
    // --- INITIALISATION ---
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML - Exemple Basique");
    window.setFramerateLimit(60); // Optionnel mais recommandé

    // Création d'un cercle (le joueur)
    sf::CircleShape player(30.f); // Rayon 30
    player.setFillColor(sf::Color::Cyan);
    player.setPosition(0.f, 270.f); // À gauche, centré verticalement (600/2 - 30)

    sf::Clock clock; // Pour gérer le temps

    // --- BOUCLE PRINCIPALE ---
    while (window.isOpen())
    {
        // 1. GESTION DU TEMPS
        float dt = clock.restart().asSeconds();

        // 2. GESTION DES ÉVÈNEMENTS (Inputs)
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Clic sur la croix rouge ou Alt+F4
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Touche Echap pour quitter
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        // 3. MISE À JOUR LOGIQUE (Update)
        // Déplacement automatique vers la droite
        player.move(150.f * dt, 0.f); 

        // Faire revenir le cercle s'il sort de l'écran
        if (player.getPosition().x > 800.f)
        {
            player.setPosition(-60.f, 270.f);
        }

        // 4. RENDU GRAPHIQUE (Draw)
        window.clear(sf::Color(50, 50, 50)); // Gris foncé pour le fond
        window.draw(player);
        window.display();
    }

    return 0;
}
```

### Prochaine étape ?

Voulez-vous que je vous montre comment remplacer le cercle par une image réelle (**Sprites et Textures**) ou comment gérer le clavier pour contrôler le personnage vous-même ?
