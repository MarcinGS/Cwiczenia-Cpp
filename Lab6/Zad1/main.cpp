/**********************************************************************************************************
 * 1. Napisz szablon funkcji max5() pobierającej jako parametr tablicę pięciu wartości typu T,            *
 * zwracającej największy element tablicy.                                                                *
 * Wielkość tablicy jest na stałe ustalona, można ją zapisać w kodzie, bez przekazywania jako parametr.   *
 * Przetestuj program przy użyciu funkcji z tablicą pięciu elementów int i double.                        *
 *********************************************************************************************************/

#include <iostream>

using namespace std;
const int SIZE = 5;

template <class T>
 T max5(T tab[]){
     T max = tab[0];
     for(int i = 1; i < SIZE; i++){
         if(tab[i] > max)
             max = tab[i];
     }
    return max;
 }

int main() {

    int tab[] = {1,3,5,7,6};
    int max = max5(tab);
    cout << max;
    return 0;
}