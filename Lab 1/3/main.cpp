//Napisz funkcje mnożącą dwie macierze

#include <iostream>

using namespace std;

void multi_matrix(int w, int k, int p) {

    /*
  A – macierz o rozmiarze w × k
  B – macierz o rozmiarze k × p
  C – macierz o rozmiarze w × p
   */

    int **A, **B, **C,
            s; //Akumulator

    //Tworzenie wierszy macierzy
    A = new int *[w];
    B = new int *[k]; //macierz B ma tyle wierszy co  A kolumn
    C = new int *[w];

    //Tworzenie kolumn w kazdym wczesniej utworzonym wierszu
    for (int i = 0; i < w; i++) {
        A[i] = new int[k];
        C[i] = new int[p];
    }

    //B ma tyle wierszy co A kolumn dlatego i < k
    for (int i = 0; i < k; i++) {
        B[i] = new int[p];
    }

    //Wypelnianie A
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            cout << "Podaj wartosci pierwszej (A) macierzy, kolejne liczby w wierszu " << (i + 1) << endl;
            cin >> A[i][j];
        }
    }

    //Wypelnianie B
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < p; j++) {
            cout << "Podaj wartosci drugiej (B) macierzy, kolejne liczby w wierszu " << (i + 1) << endl;
            cin >> B[i][j];
        }
    }

    //Mnożenie
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < p; j++) {
            s = 0; //Zerowanie akumulatora po zmianie kolumny
            for (int h = 0; h < k; h++) {
                s += A[i][h] * B[h][j]; //Wiersz A z kolumna B
                C[i][j] = s; //Zapisujemy sume w wierszu C
            }
        }
    }

    //Wyswietlanie wyniku
    cout <<  "C = A x B:\n";

    for(int i = 0; i < w; i++){
        cout << endl;
        for(int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
    }

    //Zwalnianie wierszy i kolumn (macierzy)
    for (int i = 0; i < w; i++) {
        delete[] A[i];
        delete[] C[i];
    }

    for (int i = 0; i < k; i++) {
        delete[] B[i];
        delete[] A;
        delete[] B;
        delete[] C;
    }

}
int main() {

    int w, k, p;

    cout << "Podaj liczbe wierszy macierzy A" << endl;
        cin >> w;
    cout << "Podaj liczbe kolumn macierzy A" << endl;
        cin >> k;
    cout << "Podaj liczbe kolumn macierzy B" << endl;
        cin >> p;

     multi_matrix(w,k,p);

    return 0;
}