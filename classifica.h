#ifndef TOP_MANAGER_H
#define TOP_MANAGER_H
#include <string>

// Definizione della struttura utente
typedef struct {
    std::string nome;  // Nome del giocatore
    int posizione;     // Posizione nella classifica
    int punteggio;     // Punteggio del giocatore
    int id;            // ID univoco del giocatore
} utente;

// Funzione per inizializzare la classifica
void inizializzaClassifica(utente* classifica, int dim);

// Funzione per stampare la classifica
void stampaClassifica(utente* classifica, int dim);

// Funzione che confronta due giocatori per determinare se uno ha un punteggio maggiore dell'altro
bool isMaggiore(utente* utente1, utente* utente2);

// Funzione per scambiare due giocatori senza modificare il loro ID
void scambia(utente* a, utente* b);

// Funzione che ordina la classifica usando il Bubble Sort
void bubbleSort(utente* classifica, int dim);

// Funzione per trovare il giocatore con il punteggio peggiore
int trovaPeggiore(utente* classifica, int dim);

// Funzione per ottenere l'ID massimo tra i giocatori nella classifica
int ottienID(utente* classifica, int dim);

// Funzione per aggiungere un giocatore alla classifica
void aggiungiGiocatore(utente* classifica, int dim);

// Funzione per mostrare il menu
void mostraMenu();

// Funzione per leggere un intero con gestione dell'input non valido
int leggiIntero();

#endif //TOP_MANAGER_H
