# RELAZIONE SULLE SCELTE PROGETTUALI

## LA RAPPRESENTAZIONE DEI DATI

La struttura dati principale è `utente`, definita come segue:

```cpp
typedef struct {
    std::string nome;  // Nome del giocatore
    int posizione;     // Posizione nella classifica
    int punteggio;     // Punteggio del giocatore
    int id;            // ID univoco del giocatore
} utente;

```

### Motivazioni:

- **`std::string` per il nome**: Ho scelto `std::string` per il campo del nome perché offre una gestione automatica della memoria, consentendo ai giocatori di avere nomi di lunghezza variabile.
- **`int` per posizione, punteggio e id**: Utilizzare il tipo `int` per questi campi è una scelta efficiente, assumendo che il numero di giocatori e i loro punteggi non supereranno i limiti di un intero con segno a 32 bit (che può rappresentare valori tra -2,147,483,648 e 2,147,483,647). .

### Struttura della classifica:

La classifica è implementata come un array di `utente` con dimensione fissa (`const int dim = 10`). Questa scelta è giustificata dalla semplicità di gestione della memoria e dalla prevedibilità delle prestazioni. 

### Lo scopo di “id”

La variabile id ha il ruolo di identificatore univoco che viene assegnato ad ogni giocatore. Viene incrementata ogni volta che viene assegnata ad un nuovo giocatore. La variabile id serve anche per capire quale giocatore è stato inserito per primo in classifica, la conoscenza di ciò aiuta a determinare quale giocatore deve assumere una posizione più alta in classifica in caso di punteggio pari.

---

## Funzioni

### 1. **`void inizializzaClassifica(utente* classifica, int dim)`**

Questa funzione si occupa di impostare una classifica iniziale in cui tutti i giocatori vengono rappresentati con nomi vuoti e punteggi non validi (`-1`). La posizione per ciascun giocatore è impostata uguale all’indice nell'array, che sarà poi aggiornata quando la classifica viene ordinata.

### 2. **`void stampaClassifica(utente* classifica, int dim)`**

La funzione stampa tutti i giocatori validi nella classifica, ovvero quelli il cui nome non è vuoto. Per ogni giocatore vengono visualizzati la posizione nella classifica, il nome e il punteggio. 

### 3. **`void aggiungiGiocatore(utente* classifica, int dim)`**

Questa funzione permette di aggiungere un nuovo giocatore alla classifica. Il nome e il punteggio vengono inseriti dall'utente. Prima di effettuare l'inserimento, il programma verifica se il punteggio del nuovo giocatore è superiore a quello del peggior giocatore già presente nella classifica. Se il punteggio è inferiore, il nuovo giocatore non viene aggiunto. Se un giocatore con lo stesso nome esiste già, l’utente ha la possibilità di aggiornare il punteggio esistente.

### 4. **`void bubbleSort(utente* classifica, int dim)`**

Questa funzione ordina la classifica utilizzando l’algoritmo Bubble Sort. Il confronto viene effettuato sui punteggi dei giocatori, e in caso di parità, viene usato l'ID del giocatore per determinare l'ordine. Dopo l'ordinamento, le posizioni vengono riassegnate in base all'ordine finale.

### 5. **`bool isMaggiore(utente* utente1, utente* utente2)`**

Questa funzione confronta due giocatori. Restituisce `true` se il primo giocatore ha un punteggio maggiore rispetto al secondo. In caso di parità di punteggio, il confronto si basa sugli ID, dando priorità al giocatore con ID inferiore.

### 6. **`int trovaPeggiore(utente* classifica, int dim)`**

La funzione trova l'indice del giocatore con il punteggio più basso nella classifica. Se ci sono più giocatori con lo stesso punteggio, viene scelto quello con l'ID inferiore.

Questa funzione è utile per identificare il giocatore da sostituire quando viene aggiunto un nuovo giocatore con un punteggio più alto.

### 7. **`int ottienID(utente* classifica, int dim)`**

Restituisce l'ID massimo tra i giocatori già presenti nella classifica. L'ID serve per garantire che ogni nuovo giocatore abbia un identificatore univoco. Questo ID viene poi incrementato per assegnarlo al nuovo giocatore.

L'uso dell'ID permette di distinguere univocamente i giocatori anche quando hanno lo stesso nome o punteggio.

### 8. **`void mostraMenu()` e `int leggiIntero()`**

Queste funzioni gestiscono l'interazione con l'utente. `mostraMenu()` visualizza le opzioni disponibili, mentre `leggiIntero()` si occupa di garantire che l'utente inserisca un numero intero valido.