# ÉVALUATION INDIVIDUELLE : Programmation Orientée Objet (Entraînement)

**École :** CESI ÉCOLE D'INGÉNIEURS  
**Année :** 2025-2026
**Durée de l'épreuve :** 40 minutes

**Consignes :**

* Aucun document autorisé.
* L'usage d'assistants "intelligents" ou de chatbots est **strictement interdit**.
* Veuillez utiliser l'éditeur de code fourni [Atom](https://atom-editor.cc/) - OBLIGATOIRE.
* Tous les codes sources devront être compressé et envoyé par mail à la fin de l'épreuve. (Dans notre cas d'une EI Blanche, vous pouvez simplement le déposer sur votre Github personnel et  m'envoyer le lien).

## EXERCICE 1 : Système de Gestion Financière

**Durée conseillée :** 15 minutes

Vous développez un module pour une application bancaire. Les comptes d'épargne sont définis par la classe `Livret` décrite ci-dessous.

### Spécifications (Diagramme de classe textuel)

**Classe `Livret`**

* **Attributs (privés) :**
  * `double solde` : Montant disponible sur le livret.
  * `double taux` : Taux d'intérêt annuel en % (valeur comprise entre [0.5 et 5.0]).
* **Méthodes (publiques) :**
  * `Livret()` : Constructeur par défaut.
  * `Livret(double solde, double taux)` : Constructeur avec paramètres.
  * `void setSolde(double nouv_solde)`
  * `void setTaux(double nouv_taux)`
  * `double getSolde()` : Retourne le solde actuel.
  * `double getTaux()` : Retourne le taux actuel.
  * `double getSoldePrevisionnel()` : Retourne le solde futur après ajout des intérêts (formule : `solde * (1 + taux/100)`).

### Travail à faire

Copiez le code ci-dessous dans votre éditeur et complétez les parties manquantes marquées par les commentaires `TODO` (1 à 5). **Ne modifiez pas le reste du code.**

Sauvegardez le fichier sous le nom : `exo1_[VOTRE_NOM].cpp`

```cpp
#include <iostream>
using namespace std;

// TODO 1 : Définir la classe Livret, les attributs et les prototypes des méthodes
class Livret {
    // Votre code ici...
};

// TODO 2 : Implémenter les constructeurs (par défaut et paramétré)
// ...

// TODO 3 : Implémenter les setters et getters
// (Attention : le taux doit rester tel quel si la valeur fournie n'est pas entre 0.5 et 5.0)
// ...

// TODO 4 : Implémenter la méthode getSoldePrevisionnel
// ...

int main() {
    cout << "=== Test Constructeur par defaut ===" << endl;
    Livret livret1;
    livret1.setSolde(1000);
    livret1.setTaux(2.0); 
    
    // TODO 5 : Afficher les infos pour vérifier (Attendu : Solde=1000, Taux=2%, Prev=1020)
    cout << "[CHECK] Solde: " << livret1.getSolde() << " | Taux: " << livret1.getTaux() << "%" << endl;
    cout << "[CHECK] Prevision: " << livret1.getSoldePrevisionnel() << endl;

    cout << "=== Test Constructeur parametre ===" << endl;
    Livret livret2(5000, 1.5);
    cout << "[CHECK] Solde: " << livret2.getSolde() << " | Taux: " << livret2.getTaux() << "%" << endl;
    
    if(livret2.getSoldePrevisionnel() == 5075) 
        cout << "[OK] Calcul exact" << endl;
    else 
        cout << "[ERREUR] Calcul incorrect" << endl;

    return 0;
}
```

## EXERCICE 2 : Simulation de Bataille Spatiale

**Durée conseillée :** 25 minutes

Vous travaillez sur le moteur du jeu "Galactic Battle". Vous devez implémenter une hiérarchie de vaisseaux spatiaux et gérer leur système de propulsion.

### 1. Analyse des Diagrammes

**Diagramme de Classe (Description) :**

* **Classe Abstraite `Vaisseau`**

  * `# string nom` (Nom du vaisseau)
  * `# int blindage` (Points de vie)
  * `+ Vaisseau(string nom, int blindage)`
  * `+ virtual void status()` : Affiche le nom et le blindage.
  * `+ virtual int puissance()` : **Méthode virtuelle pure**.

* **Classe `Croiseur` (Hérite de Vaisseau)**

  * `- int canons` (Nombre de canons laser)
  * `- Moteur* moteur` (Pointeur vers un objet Moteur)
  * `+ Croiseur(string nom, int blindage, int canons)`
  * `+ void status()` : Affiche le nom, le blindage, le nombre de canons et la puissance du moteur.
  * `+ int puissance()` : Retourne la puissance de feu totale (formule : `canons * puissance_moteur`).

* **Classe `Moteur`**

  * `- int chevaux` (Puissance en chevaux)
  * `+ Moteur(int ch)`
  * `+ int getChevaux()`

**Diagramme de Séquence (Logique métier) :**

1. Le `main` instancie un `Croiseur`.
2. **Règle d'or (Composition) :** Le moteur est indissociable du Croiseur. Il doit être instancié dynamiquement (avec `new`) à l'intérieur du constructeur du `Croiseur` (valeur fixée arbitrairement à 100 ch).
3. Lorsque le `Croiseur` est détruit, son moteur doit être détruit automatiquement.
4. L'appel à `status()` ou `puissance()` sur le croiseur nécessite d'appeler `getChevaux()` sur l'objet moteur interne.

### 2. Travail à faire

Tout le code doit être écrit dans un seul fichier : `exo2_[VOTRE_NOM].cpp`.

1. **Implémentation des classes :** Définissez les classes `Vaisseau`, `Croiseur` et `Moteur` en respectant l'encapsulation, l'héritage et le polymorphisme décrits ci-dessus.
2. **Gestion de la mémoire :** Assurez-vous qu'il n'y a aucune fuite de mémoire. Le destructeur du `Croiseur` est critique ici.
3. **Fonction Principale :** Réalisez un `main` qui :
      * Crée un pointeur de type `Vaisseau` instancié en `Croiseur` ("Imperator", 5000 PV, 10 canons).
      * Appelle `status()`.
      * Affiche la puissance de feu.
      * Libère la mémoire correctement.
4. **Compteur de Vaisseaux (Statistique) :**
      * Nous voulons savoir combien de vaisseaux sont instanciés en temps réel.
      * Ajoutez un attribut statique `nbVaisseaux` dans la classe `Vaisseau`.
      * Ce compteur doit s'incrémenter à la création d'un vaisseau et se décrémenter à sa destruction.
      * Affichez la valeur de ce compteur dans le `main` pour prouver qu'il fonctionne (avant la création, après la création, et après la suppression).
