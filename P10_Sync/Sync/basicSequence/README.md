# 4.2 Aufgabe: Einfache Reihenfolge

## a)

### Schritt 1: Prozesse (Threads) der Problemstellung identifizieren. 

* Kaffeeautomat
* Kunde A
* Kunde B

### Schritt 2: Ausführungsschritte der einzelnen Prozesse (Threads) ermitteln. 

| KaffeeMaschine | Kunde A    |
| :------------- | :---------- |
| ist bereit | wartet bis am Zug|
| wartet auf Geld | wirft Geld ein  |
| gibt Kaffee aus   | wartet auf Kaffee |
| wartet auf Freigabe | gibt KaffeeMaschine frei |

### Schritt 3: Synchronisationsbedingungen ermitteln.

1. am Zug (myTurn)
1. Geld (coin)
1. Kaffee (coffee)
1. Freigabe (ready)

### Schritt 4: Benötigte Semaphore definieren.

* myTurn = sem_open(MYTURN_SEMAPHOR, O_CREAT, 0700, 1); checkSem(myTurn); 
* coin = sem_open(COIN_SEMAPHOR, O_CREAT, 0700, 0); checkSem(coin); 
* coffee = sem_open(COFFEE_SEMAPHOR, O_CREAT, 0700, 0); checkSem(coffee); 
* ready = sem_open(READY_SEMAPHOR, O_CREAT, 0700, 0); checkSem(ready);

### Schritt 5: Prozesse mit Semaphore Operationen ergänzen. 

siehe code.

### Schritt 6; Implementation

siehe code.

## b)

siehe code.

## c)

Ja.