/*Napisz funkcję, która znajduje w tablicy element maksymalny.
 * Parametrami funkcji mają być: tablica tab oraz liczba elementów tablicy – n.
 * Wartością funkcji ma być element maksymalny.*/


#include <iostream>

using namespace std;

int find_max(int tab[], int n){

    int max = tab[0]; // Inicjalizacja pierwszym elementem

    for(int i = 1; i < n; i++){
        if (tab[i] > max)
            max = tab[i];
    }
    return max;
}

int main() {

    int tab[5] = {1,5,4,9,2};
    cout << find_max(tab,5);
    return 0;
}