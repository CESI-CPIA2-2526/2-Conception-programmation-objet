#include <iostream>
#include <string>
using namespace std;

// --- CLASSE MOTEUR (Composant) ---
class Moteur {
private:
    int chevaux;
public:
    Moteur(int ch) {
        this->chevaux = ch;
    }
    int getChevaux() {
        return this->chevaux;
    }
};

// --- CLASSE ABSTRAITE VAISSEAU ---
class Vaisseau {
protected:
    string nom;
    int blindage;

public:
    // Attribut statique
    static int nbVaisseaux;

    Vaisseau(string nom, int blindage) {
        this->nom = nom;
        this->blindage = blindage;
        // Incrémentation du compteur statique
        nbVaisseaux++;
    }

    // Destructeur VIRTUEL (Crucial pour le polymorphisme)
    virtual ~Vaisseau() {
        // Décrémentation du compteur statique
        nbVaisseaux--;
        cout << "[DEBUG] Destruction d'un Vaisseau générique." << endl;
    }

    virtual void status() {
        cout << "Vaisseau : " << this->nom << " | Blindage : " << this->blindage << endl;
    }

    // Méthode virtuelle pure
    virtual int puissance() = 0;
};

// Initialisation de l'attribut statique (OBLIGATOIRE hors de la classe)
int Vaisseau::nbVaisseaux = 0;

// --- CLASSE CROISEUR (Héritage) ---
class Croiseur : public Vaisseau {
private:
    int canons;
    Moteur* moteur; // Composition (Pointeur)

public:
    Croiseur(string nom, int blindage, int canons) : Vaisseau(nom, blindage) {
        this->canons = canons;
        // Instanciation dynamique du moteur (Composition)
        this->moteur = new Moteur(100); 
    }

    ~Croiseur() {
        // Libération de la mémoire (Composition)
        delete this->moteur;
        cout << "[DEBUG] Destruction du Croiseur et de son Moteur." << endl;
    }

    void status() override { // override est optionnel mais recommandé
        // Appel de la méthode parente
        Vaisseau::status();
        cout << " - Type: Croiseur" << endl;
        cout << " - Canons: " << this->canons << endl;
        cout << " - Moteur: " << this->moteur->getChevaux() << " ch" << endl;
    }

    int puissance() override {
        return this->canons * this->moteur->getChevaux();
    }
};

// --- MAIN ---
int main() {
    cout << "=== DEBUT DU PROGRAMME ===" << endl;
    cout << "Nombre de vaisseaux actuel : " << Vaisseau::nbVaisseaux << endl;

    // 1. Création avec polymorphisme
    cout << "\n--- Instanciation ---" << endl;
    Vaisseau* v1 = new Croiseur("Imperator", 5000, 10);
    
    cout << "Nombre de vaisseaux apres creation : " << Vaisseau::nbVaisseaux << endl;

    // 2. Utilisation
    cout << "\n--- Statut et Puissance ---" << endl;
    v1->status();
    cout << "Puissance de feu totale : " << v1->puissance() << " degats." << endl;

    // 3. Nettoyage
    cout << "\n--- Suppression ---" << endl;
    delete v1; // Appelle ~Croiseur() grâce au destructeur virtuel de Vaisseau

    cout << "\n--- Verification Memoire ---" << endl;
    cout << "Nombre de vaisseaux final : " << Vaisseau::nbVaisseaux << endl;

    return 0;
}
