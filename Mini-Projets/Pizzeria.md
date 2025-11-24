# Mini-Projet : La Pizzeria de Luigi

**Consigne :** Vous devez créer les classes nécessaires pour que le `main.cpp` fourni à la fin compile et produise le résultat attendu.

## 1\. Le Scénario

La pizzeria "Luigi's Tech" installe des bornes de commande. Votre mission est de développer le noyau logiciel qui gère la **Carte** (le menu).
La carte contient des éléments très différents (Pizzas, Boissons) qui doivent pourtant être stockés dans une seule et même liste.

## 2\. Architecture attendue

Vous devez concevoir 3 fichiers d'en-tête (`.hpp`) et leurs implémentations (`.cpp`).

### A. La Base : `ElementCarte` (Abstraite)

C'est le concept générique de "quelque chose qu'on peut vendre".

  * **Données :** Chaque élément possède un **nom** et un **prix**.
  * **Comportement :**
      * Tout élément doit pouvoir **s'afficher** (`afficher()`), mais chaque type d'élément s'affiche différemment (méthode virtuelle pure).
      * Tout élément a un destructeur (⚠️ Attention au type de destructeur requis pour le polymorphisme).

### B. Les Produits (Concrets)

Vous devez créer deux spécialisations :

1.  **`Pizza`** : C'est un `ElementCarte`.
      * Elle possède en plus une liste d'**ingrédients** (ex: `std::vector<std::string>`).
      * Quand elle s'affiche, elle doit lister ses ingrédients sous son nom.
2.  **`Boisson`** : C'est un `ElementCarte`.
      * Elle possède en plus un **volume** en centilitres (`int`).
      * Quand elle s'affiche, elle doit préciser "Format : X cl".

### C. Le Gestionnaire : `Carte`

C'est la classe qui gère la liste des produits disponibles.

  * Elle stocke les produits. **Contrainte :** Utilisation obligatoire de `std::vector` et `std::unique_ptr`.
  * Elle permet d'ajouter un produit.
  * Elle permet d'afficher toute la carte (boucle polymorphique).
  * Elle permet de calculer le prix total des éléments présents dans la carte.



## 3\. `main.cpp`

Voici le code que vous devez faire fonctionner. Copiez-le dans votre `main.cpp`.
**INTERDICTION DE MODIFIER CE FICHIER.** Si vous devez le modifier, c'est que vos classes sont mal conçues.

```cpp
#include <iostream>
#include <vector>
#include <memory>
// Vos includes ici :
#include "Carte.hpp"
#include "Pizza.hpp"
#include "Boisson.hpp"

int main() {
    std::cout << "=== INITIALISATION DE LA CARTE ===" << std::endl;
    Carte menuDuJour;

    // 1. Création d'une Pizza
    // Notez la syntaxe : on crée dynamiquement sans 'new'
    auto p1 = std::make_unique<Pizza>("Reine", 12.50);
    p1->ajouterIngredient("Jambon");
    p1->ajouterIngredient("Champignons");
    p1->ajouterIngredient("Mozzarella");

    // 2. Création d'une Boisson
    auto b1 = std::make_unique<Boisson>("Coca-Cola", 3.00, 33); // Nom, Prix, Volume
    auto b2 = std::make_unique<Boisson>("Chianti", 15.00, 75);

    // 3. Remplissage de la carte
    // Attention : on 'move' les pointeurs car ils sont uniques !
    menuDuJour.ajouter(std::move(p1));
    menuDuJour.ajouter(std::move(b1));
    menuDuJour.ajouter(std::move(b2));

    // 4. Utilisation du polymorphisme
    std::cout << "\n=== AFFICHAGE DU MENU ===" << std::endl;
    menuDuJour.afficherTout(); 
    // Doit afficher les ingrédients pour la pizza, et le volume pour les boissons

    std::cout << "\n=== TOTAL COMMANDE ===" << std::endl;
    std::cout << "Total : " << menuDuJour.calculerTotal() << " euros" << std::endl;

    return 0;
} 
// Ici, tous les destructeurs doivent s'enchainer correctement.
// Vérifiez avec Valgrind qu'il n'y a pas de fuites !
```



## 4\. Résultat attendu (Sortie console)

Votre programme doit produire exactement ceci :

```text
=== INITIALISATION DE LA CARTE ===

=== AFFICHAGE DU MENU ===
- Pizza Reine (12.5 euros)
  Ingrédients : Jambon, Champignons, Mozzarella
- Boisson Coca-Cola (3 euros)
  Format : 33cl
- Boisson Chianti (15 euros)
  Format : 75cl

=== TOTAL COMMANDE ===
Total : 30.5 euros
```



## 5\. Indices & Pièges à éviter (Checklist)

Si vous bloquez, consultez cette liste :

1.  **Erreur de compilation `deleted function` ?**
      * C'est surement dans `Carte::ajouter`. Un `unique_ptr` ne se copie pas. Votre fonction doit prendre le paramètre par valeur (`std::unique_ptr<ElementCarte> e`) et vous devez utiliser `std::move` lors de l'appel (déjà fait dans le main) ET lors de l'insertion dans le vecteur (`vec.push_back(std::move(e))`).
2.  **Destructeur manquant ?**
      * Dans `ElementCarte`, si le destructeur n'est pas **virtuel**, vous aurez des problèmes de mémoire.
3.  **Affichage** :
      * La méthode `afficher()` doit être `virtual` dans le parent et `override` dans les enfants.
4.  **Organisation** :
      * N'oubliez pas les `#ifndef` / `#define` (Include Guards) ou `#pragma once` dans vos fichiers `.hpp`.
