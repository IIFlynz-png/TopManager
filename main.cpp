#include <iostream>
using namespace std;
#include"top_manager.h"

int main() {
    const int dim = 10;
    utente classifica[dim];

    // Inizializza la classifica con posizioni e punteggi vuoti
    inizializzaClassifica(classifica, dim);


    int scelta = 0;

    while (scelta != 3) {
        mostraMenu();
        scelta = leggiIntero();

        switch (scelta) {
            case 1:
                cout << "\nClassifica attuale:\n";
            stampaClassifica(classifica, dim);
            break;
            case 2:
                aggiungiGiocatore(classifica, dim);
            break;
            case 3:
                cout << "Uscita dal programma\n";
            break;
            default:
                cout << "Opzione non valida. Riprova.\n";
            break;
        }
    }

    return 0;
}
