#include <iostream>
using namespace std;

// 1. Définition de la classe
class Livret {
private:
    double solde;
    double taux;

public:
    // 2. Constructeurs
    Livret() {
        this->solde = 0;
        this->taux = 0; // Ou une valeur par défaut valide, ex: 0.5
    }

    Livret(double solde, double taux) {
        this->solde = solde;
        // On réutilise le setter pour garantir la vérification dès la construction
        // Si le taux est invalide, on pourrait mettre une valeur par défaut
        if (taux >= 0.5 && taux <= 5.0) {
            this->taux = taux;
        } else {
            this->taux = 0.5; // Valeur par défaut de sécurité
        }
    }

    // 3. Setters et Getters
    void setSolde(double nouv_solde) {
        this->solde = nouv_solde;
    }

    void setTaux(double nouv_taux) {
        // Vérification des bornes
        if (nouv_taux >= 0.5 && nouv_taux <= 5.0) {
            this->taux = nouv_taux;
        } else {
            cout << "[AVERTISSEMENT] Taux invalide (" << nouv_taux << "%). Modification ignoree." << endl;
        }
    }

    double getSolde() {
        return this->solde;
    }

    double getTaux() {
        return this->taux;
    }

    // 4. Méthode de calcul
    double getSoldePrevisionnel() {
        // Formule : solde * (1 + taux/100)
        return this->solde * (1.0 + (this->taux / 100.0));
    }
};

int main() {
    cout << "=== Test Constructeur par defaut ===" << endl;
    Livret livret1;
    livret1.setSolde(1000);
    livret1.setTaux(2.0); // Valide
    livret1.setTaux(10.0); // Invalide, doit être ignoré

    // 5. Affichage
    cout << "[CHECK] Solde: " << livret1.getSolde() << " | Taux: " << livret1.getTaux() << "%" << endl;
    cout << "[CHECK] Prevision: " << livret1.getSoldePrevisionnel() << endl;

    cout << "=== Test Constructeur parametre ===" << endl;
    Livret livret2(5000, 1.5);
    cout << "[CHECK] Solde: " << livret2.getSolde() << " | Taux: " << livret2.getTaux() << "%" << endl;
    
    if(livret2.getSoldePrevisionnel() == 5075) 
        cout << "[OK] Calcul exact" << endl;
    else 
        cout << "[ERREUR] Calcul incorrect : " << livret2.getSoldePrevisionnel() << endl;

    return 0;
}
