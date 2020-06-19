/****************************************************************************************************
 * 3. Napisać program, w którym zostaną zaimplementowane 3 funkcje sortujące                        *
 * (algorytmem bąbelkowym, przez wstawianie oraz quicksort) z wykorzystaniem szablonów funkcji.     *
 * Należy zaprezentować ich zastosowanie dla różnych rodzajów danych wejściowych.                   *
 * Funkcje powinny przyjmować jako parametr tablice do posortowania oraz liczbę elementów w tablicy.*
 ***************************************************************************************************/

#include <iostream>

using namespace std;

template <class T>
 void bublesort(T *tab, T n){
    T box;
    for(int i = 0; i < (n-1); i++){
        for(int j = 0; j < (n-1); j++){
            if(tab[j] > tab[j+1]) {
                box = tab[j];
                tab[j] = tab[j + 1];
                tab[j+1] = box;
            }
        }
    }
}

template <class T>
void insertSort(T *tab, T n){
    T box;
    for(int i = 1; i < n; i++){
        int j = i;
        while (j > 0 && (tab[j-1] > tab[j])){
            box = tab[j];
            tab[j] = tab[j-1];
            tab[j-1] = box;
            j--;
        }
    }
}

template <class T>
void quickSort(T *tab, int left, int right ){

    int i,j;
    T piwot,box;

    i = (left + right)/2;
    piwot = tab[i];
    tab[i] = tab[right];

    for(j=i=left; i < right; i++) {
        if (tab[i] < piwot) {
            box = tab[i];
            tab[i] = tab[j];
            tab[j] = box;
            j++;
        }
    }
    tab[right] = tab[j];
    tab[j] = piwot;

    if(left < (j-1))
        quickSort(tab,left,(j-1));
    if((j+1) < right)
        quickSort(tab,(j+1),right);
}

int main() {
    int intTab[5] = {5,2,13,8,21};
    double doubTab[5] = {4.4,19.3,8.8,32.12,7.4};

    int intTab2[5] = {54,76,14,42,22};
    double doubTab2[5] = {18.98,91.3,65.34,37.17,16.1};

    int intTab3[5] = {5,67,65,21,254};
    double doubTab3[5] = {18.98,91.3,65.34,37.17,16.1};

   quickSort(intTab,0,4);
    for(int i = 0; i < 5; i++){
        cout << intTab[i]<<"|";
    }
    cout << " quicksort dla int" << endl;

   quickSort(doubTab,0.,4.);
    for(int i = 0; i < 5; i++){
        cout << doubTab[i]<<"|";
    }
    cout << " quicksort dla double" << endl;

    insertSort(intTab2,5);
    for(int i = 0; i < 5; i++){
        cout << intTab2[i]<<"|";
    }
    cout << " insert sort dla int" << endl;

    insertSort(doubTab2, 5.);
    for(int i = 0; i < 5; i++){
        cout << doubTab2[i]<<"|";
    }
    cout << " inser sort dla double" << endl;

    bublesort(intTab3,5);
    for(int i = 0; i < 5; i++){
        cout << intTab3[i]<<"|";
    }
    cout << " bublesort dla int" << endl;

    bublesort(doubTab3, 5.);
    for(int i = 0; i < 5; i++){
        cout << doubTab3[i]<<"|";
    }
    cout << " bublesort dla double" << endl;

    return 0;
}