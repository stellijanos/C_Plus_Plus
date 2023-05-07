#include <iostream>
#include <cmath>
// Owner: Janos Stelli
using namespace std;

//Ein boolean was true zuruckgibt, wenn ein Zahl Primzahl ist
bool primzahl(int zahl) {
    for (int teiler = 2; teiler <= trunc(sqrt(zahl)); teiler++) {
        if (zahl % teiler == 0) return false;
    }
    return true;
}

//druckt ein Vektor mit "anzahl" Elementen aus
void ausdruckenReihe(int reihe[1000], int anzahl) {
    for (int i = 0; i < anzahl; i++) {
        cout << reihe[i] << ' ';
    }
}

int grossteGemeinsameTeiler(int ersteZahl, int zweiteZahl) {
    while (ersteZahl != zweiteZahl) {
        if (ersteZahl > zweiteZahl) {
            ersteZahl -= zweiteZahl;
        } else if (zweiteZahl > ersteZahl) {
            zweiteZahl -= ersteZahl;
        }
    }
    return ersteZahl;
}

void firstNPrimeNUmbers() {   // Problem 2. Punkt a.
    int counter, anzahl, erstenNPrimzahlen[1001];
    cout << "Geben Sie bitte die Lange der ersten Primzahlfolge ein" << endl;
    cin >> anzahl;
    if (anzahl > 1000) {
        cout << "Falsche Eingabe";
        return;
    }
    counter = 0;
    //counter zahlt die Anzahl der Primzahlen und dessen Wert wird maximum Wert von "anzahl" sein

    for (int zahl = 2; counter <= anzahl; zahl++) {
        if (primzahl(zahl)) {
            erstenNPrimzahlen[counter] = zahl;
            counter++;
        }
    }
    ausdruckenReihe(erstenNPrimzahlen, anzahl);
}

// Problem 2. Punkt b.
void longestRelativePrimeRow() {
    int counter, maxCounter, anzahl, reihe[1001], langsteKette[1001], auxKette[1001];

    cout << "\nGeben Sie die Anzahl der Reihe von Zahlen: ";
    cin >> anzahl;
    cout << "Geben Sie die Elemente der Reihe an: ";
    if (anzahl > 1000) cout << "Falsche Eingabe";

    for (int i = 0; i < anzahl; i++) {   //einlesen der Reihe
        cin >> reihe[i];
    }

    auxKette[0] = reihe[0];
    counter = 1;
    maxCounter = 0;

    for (int i = 1; i < anzahl; i++) {
        if (grossteGemeinsameTeiler(reihe[i - 1], reihe[i]) == 1) {
            auxKette[counter] = reihe[i];
            counter++;
        } else {
            if (counter > maxCounter) {
                for (int j = 0; j < counter; j++) {
                    langsteKette[j] = auxKette[j];
                }
                maxCounter = counter;
            }
            auxKette[0] = reihe[i];
            counter = 1;
        }
    }

// Uberprufen wegen der letzten Element der Reihe
    if (counter > maxCounter) {
        for (int j = 0; j < counter; j++) {
            langsteKette[j] = auxKette[j];
        }
        maxCounter = counter;
    }
    ausdruckenReihe(langsteKette, maxCounter);
}

int main() {
    firstNPrimeNUmbers();
    longestRelativePrimeRow();
    return 0;
}
