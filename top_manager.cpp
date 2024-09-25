#include "top_manager.h"
#include <string>
#include <iostream>
using namespace std;


// Trovare modo per gestire id
// Aggiorna la posizione (variabile)

void mostraMenu() {
	cout << "\nMenu:\n";
	cout << "1. Visualizza la classifica\n";
	cout << "2. Aggiungi un nuovo giocatore\n";
	cout << "3. Esci\n";
	cout << "Scegli un'opzione: ";
}

int leggiIntero() {
	int valore;
	string input;

	while (true) {
		cin >> input;

		// Verifico che l'input sia composto solo da cifre
		bool valido = true;
		for (char c : input) {
			if (!isdigit(c)) {
				valido = false;
				break;
			}
		}

		if (valido) {
			valore = stoi(input);
			if (valore >= 0) {
				return valore;
			}
		}
		cout << "Input non valido, inserire un numero positivo: ";
	}
}


void inizializzaClassifica(utente* classifica, int dim) {
	for (int i = 0; i < dim; i++) {
		classifica[i] = { "", i, -1, i};
	}
}

// Funzione per stampare la classifica
void stampaClassifica(utente* classifica, int dim) {
	for (int i = 0; i < dim; i++) {
		if (classifica[i].nome != "")
			cout << classifica[i].posizione << ". " << classifica[i].nome << ": " << classifica[i].punteggio << endl;
	}
}


// Funzione per determinare se un giocatore ha un punteggio superiore ad un altro
bool isMaggiore(utente* utente1, utente *utente2) {
	if (utente1->punteggio > utente2->punteggio) {
		return true;
	}
	else if (utente1->punteggio < utente2->punteggio) {
		return false;
	}
	else if (utente1->id < utente2->id) {
		return true;
	}
	return false;

}


// Funzioni per riordinare

// Funzione per scambiare due giocatori
void scambia(utente* a, utente* b) {
	std::string tempNome = a->nome;
	int tempPosizione = a->posizione;
	int tempPunteggio = a->punteggio;

	a->nome = b->nome;
	a->posizione = b->posizione;
	a->punteggio = b->punteggio;

	b->nome = tempNome;
	b->posizione = tempPosizione;
	b->punteggio = tempPunteggio;
}


void bubbleSort(utente* classifica, int dim) {
	bool scambiato;
	for (int i = 0; i < dim - 1; i++) {
		scambiato = false;
		for (int j = 0; j < dim - i - 1; j++) {
			if (!isMaggiore(&classifica[j], &classifica[j + 1])) {
				scambia(&classifica[j], &classifica[j + 1]);
				scambiato = true;
			}
		}
		if (!scambiato) {
			break;
		}
	}
	// Aggiorna solo la posizione dei giocatori validi
	int posizione = 0;
	for (int i = 0; i < dim; i++) {
		if (classifica[i].nome != "") {
			classifica[i].posizione = posizione++;
		}
	}
}




// Funzione per trovare l'indice del peggiore
int trovaPeggiore(utente* classifica, int dim) {
	int peggioreIndex = 0;
	for (int i = 1; i < dim; i++) {
		if (classifica[i].punteggio < classifica[peggioreIndex].punteggio ||
			(classifica[i].punteggio == classifica[peggioreIndex].punteggio && classifica[i].id < classifica[peggioreIndex].id)) {
			peggioreIndex = i;
			}
	}
	return peggioreIndex;
}



// Funzione per ottenere ID massimo
int ottienID(utente* classifica, int dim) {
	if (dim == 0) {
		return -1;
	}

	int maxID = classifica[0].id;

	for (int i = 1; i < dim; i++) {

		if (classifica[i].id > maxID) {
			maxID = classifica[i].id;
		}
	}

	return maxID;
}


void aggiungiGiocatore(utente* classifica, int dim) {
	utente giocatore;
	cout << "Inserisci il nome del giocatore: ";
	cin >> giocatore.nome;
	cout << "Inserisci il punteggio del giocatore: ";
	cin >> giocatore.punteggio;

	// Trova il giocatore peggiore
	int peggiorIndex = trovaPeggiore(classifica, dim);

	// Controlla se il nuovo punteggio e' superiore a quello del peggiore
	if (giocatore.punteggio > classifica[peggiorIndex].punteggio) {
		// Verifica se il giocatore e' già presente nella classifica
		for (int i = 0; i < dim; i++) {
			if (classifica[i].nome == giocatore.nome) {
				cout << "Il giocatore \"" << giocatore.nome << "\" e' già presente nella classifica!" << endl;
				cout << "Vuoi sovrascrivere il punteggio? (s/n): ";
				char scelta;
				cin >> scelta;
				if (scelta == 's' || scelta == 'S') {
					giocatore.id = classifica[i].id;  // Mantieni lo stesso ID
					classifica[i] = giocatore;
					bubbleSort(classifica, dim);
					cout << "Il punteggio del giocatore \"" << giocatore.nome << "\" e' stato aggiornato!" << endl;
				} else {
					cout << "Il punteggio del giocatore \"" << giocatore.nome << "\" non e' stato aggiornato." << endl;
				}
				return;
			}
		}

		// Assegna il nuovo ID in base all'ordine di aggiunta
		giocatore.id = ottienID(classifica, dim) + 1;
		classifica[peggiorIndex] = giocatore;
		bubbleSort(classifica, dim);
		cout << "Il giocatore \"" << giocatore.nome << "\" e' stato aggiunto con successo!" << endl;
	} else {
		cout << "Il punteggio del giocatore \"" << giocatore.nome << "\" non e' sufficiente per entrare in classifica!" << endl;
		cout << "Punteggio attuale del peggiore: " << classifica[peggiorIndex].punteggio << endl;
	}
}
