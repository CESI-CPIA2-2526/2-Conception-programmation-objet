# ÉVALUATION BLANCHE : PROJET "LOGISOFT"

* **Durée conseillée :** 40 minutes
* **Contexte :** Vous développez le noyau d'une application de gestion de transports pour l'entreprise "LogiSoft".
* Le faire sur <https://www.online-cpp.com/>

## Analyse Technique (Cahier des Charges)

**1. Le composant `Moteur`**

* C'est une classe simple représentant le moteur d'un véhicule.
* **Attributs (privés) :** `int puissance` (chevaux).
* **Méthodes :** Constructeur, getter.

**2. La classe abstraite `Vehicule`**

* **Attributs (protégés) :** `string marque`, `int id`.
* **Attribut Statique (privé) :** `compteur` (compte le nombre total de véhicules créés).
* **Méthodes :**
  * Constructeur : Initialise marque/id et incrémente le compteur.
  * Destructeur (**Virtuel**) : Décrémente le compteur.
  * `afficher()` (**Virtuelle**) : Affiche la marque et l'ID.
  * `vitesseMax()` (**Virtuelle Pure**) : Retourne la vitesse max (entier).
  * `getCompteur()` (**Statique**) : Retourne le nombre de véhicules en mémoire.

**3. La classe `Camion` (Hérite de `Vehicule`)**

* Un camion **possède** un `Moteur`. C'est une **composition forte** : le moteur est créé à la naissance du camion et détruit à sa mort.
* **Attributs (privés) :** `float poidsCharge` (en tonnes), `Moteur* sonMoteur` (Pointeur \!).
* **Méthodes :**
  * Constructeur : Prend marque, ID, charge et puissance moteur. Doit instancier le `Moteur` avec `new`.
  * Destructeur : Doit supprimer le `Moteur` pour éviter les fuites mémoire.
  * `vitesseMax()` : Retourne 90 (vitesse légale).
  * `afficher()` : Affiche les infos du parent + la charge + la puissance du moteur.

### Code à Compléter

Copiez ce code et remplacez les **`// TODO ...`** par votre code.

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// -------------------------------------------------------
// CLASSE COMPOSANT : MOTEUR
// -------------------------------------------------------
class Moteur {
private:
    int puissance;
public:
    Moteur(int p) : puissance(p) {}
    int getPuissance() const { return puissance; }
};

// -------------------------------------------------------
// CLASSE MÈRE ABSTRAITE : VEHICULE
// -------------------------------------------------------
class Vehicule {
protected:
    string marque;
    int id;
    // TODO 1 : Déclarer l'attribut statique 'compteur'
    

public:
    Vehicule(string m, int i) : marque(m), id(i) {
        // TODO 2 : Incrémenter le compteur
        
    }

    // TODO 3 : Créer le destructeur virtuel qui décrémente le compteur
    // (Affichez un message "Destruction Vehicule" pour le debug)
    

    virtual void afficher() const {
        cout << "Vehicule [" << id << "] " << marque;
    }

    // TODO 4 : Déclarer la méthode virtuelle pure vitesseMax()
    

    // TODO 5 : Définir la méthode statique getCompteur()
    
};

// TODO 6 : Initialiser l'attribut statique à 0 (Hors de la classe)


// -------------------------------------------------------
// CLASSE FILLE : CAMION
// -------------------------------------------------------
class Camion : public Vehicule {
private:
    float poidsCharge;
    Moteur* sonMoteur; // Composition

public:
    // TODO 7 : Implémenter le constructeur complet
    // Note : Il doit appeler le constructeur de Vehicule
    // Note : Il doit allouer dynamiquement (new) le moteur
    Camion(string m, int i, float charge, int chevaux) : Vehicule(m, i) {
        this->poidsCharge = charge;
        // ... instanciation du moteur ici ...
    }

    // TODO 8 : Implémenter le destructeur
    // Note : Il doit supprimer (delete) le moteur
    ~Camion() {
        cout << "Destruction Camion..." << endl;
        // ... nettoyage mémoire ici ...
    }

    // TODO 9 : Redéfinir vitesseMax (retourne 90)
    

    // TODO 10 : Redéfinir afficher()
    // Elle doit appeler afficher() du parent, puis afficher charge et puissance moteur
    void afficher() const override {
        // ... appel parent ...
        // ... affichage specifique ...
    }
};

// -------------------------------------------------------
// MAIN
// -------------------------------------------------------
int main() {
    cout << "--- DEBUT PROGRAMME ---" << endl;
    cout << "Parc actuel : " << Vehicule::getCompteur() << endl;

    // TODO 11 : Créer un pointeur de Vehicule instancié en Camion
    // Marque: "Volvo", ID: 101, Charge: 15.5 tonnes, Moteur: 450ch
    

    cout << "Parc actuel (apres creation) : " << Vehicule::getCompteur() << endl;

    // TODO 12 : Appeler afficher() et afficher la vitesse max sur l'objet créé
    // Test du polymorphisme
    

    cout << "\n--- FIN DE VIE ---" << endl;
    
    // TODO 13 : Supprimer l'objet proprement
    

    cout << "Parc actuel (apres suppression) : " << Vehicule::getCompteur() << endl;

    return 0;
}
```
