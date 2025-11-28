# Aide-mémoire SFML : Projet Jeu de la Vie

Ce document regroupe les fonctions SFML indispensables pour respecter les contraintes techniques du projet (Optimisation, Caméra, HUD).

## Tableau des Commandes Essentielles

| Catégorie | Commande / Classe | Utilité spécifique pour ce projet |
| :--- | :--- | :--- |
| **Optimisation (Rendu)** | `sf::VertexArray grid(sf::Quads, N * 4)` | **Crucial.** Remplace les milliers de `sf::RectangleShape`. Crée un tableau unique de sommets pour dessiner toute la grille en un appel GPU. |
| | `grid[i].position = ...` | Définit la position des coins d'une cellule (à calculer une seule fois à l'initialisation). |
| | `grid[i].color = sf::Color::...` | Change la couleur (Blanc=Vivante, Noir=Morte) selon l'état de la grille logique (à faire dans la boucle de rendu). |
| **Caméra (Zoom/Pan)** | `sf::View view` | Crée une caméra virtuelle pour gérer le zoom et le déplacement sans modifier les coordonnées réelles des cellules. |
| | `view.zoom(factor)` | Zoome (`factor < 1`, ex: 0.9) ou dézoome (`factor > 1`, ex: 1.1). |
| | `view.move(dx, dy)` | Déplace la caméra latéralement (pour le "Pan" avec le clic droit). |
| | `window.setView(view)` | **Active la caméra** avant de dessiner la grille. |
| | `window.setView(window.getDefaultView())` | **Remet la vue à plat** (1:1). Indispensable avant de dessiner le texte (HUD) pour qu'il ne subisse pas le zoom. |
| **Souris & Coordonnées** | `window.mapPixelToCoords(pos, view)` | **La fonction clé.** Convertit un clic souris (pixels écran) en coordonnées du monde (jeu) en tenant compte du zoom et du déplacement actuels. |
| | `sf::Mouse::getPosition(window)` | Récupère la position brute de la souris dans la fenêtre (en pixels). |
| **Interface (HUD)** | `sf::Font` & `sf::Text` | Affiche les infos (Génération, Population, Vitesse). |
| | `font.loadFromFile("arial.ttf")` | Charge la police (obligatoire avant utilisation). |
| | `text.setString(std::string)` | Met à jour le texte affiché (nécessite `#include <string>`). |
| **Boucle & Base** | `window.clear(sf::Color::Black)` | Efface l'image précédente (début de frame). |
| | `window.draw(vertexArray)` | Dessine toute la grille optimisée en une seule instruction. |
| | `window.display()` | Affiche le résultat final (fin de frame). |
| **Entrées (Events)** | `if (event.type == sf::Event::KeyPressed)` | Pour les actions "uniques" (Pause, Next Gen, Reset). Évite que l'action se répète 60 fois par seconde. |
| **Entrées (Temps réel)**| `sf::Keyboard::isKeyPressed(...)` | Pour les actions continues (ex: Zoom fluide si géré par clavier). |
| | `sf::Mouse::isButtonPressed(...)` | Vérifie si le clic gauche (dessin) ou droit (caméra) est maintenu. |
| **Temps** | `sf::Clock` / `sf::Time` | Permet de gérer la vitesse de simulation (ex: update la logique seulement tous les 100ms). |

---

## Gestion de la Vitesse de Simulation

Le sujet demande de pouvoir accélérer ou ralentir la simulation avec `+` et `-`.
Il faut séparer le **framerate de rendu** (60 FPS) de la **vitesse de jeu** (1 tour tous les X ms).

| Concept | Implémentation |
| :--- | :--- |
| **Délai variable** | Créer une variable `float simulationDelay = 0.1f;` (100ms). |
| **Accélérer** | Touche `+` : `simulationDelay /= 2.0f;` (Divise le temps d'attente). |
| **Ralentir** | Touche `-` : `simulationDelay *= 2.0f;` (Augmente le temps d'attente). |
| **Timer** | Utiliser un accumulateur de temps dans la boucle principale. |

