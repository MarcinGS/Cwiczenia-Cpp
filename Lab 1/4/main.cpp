/*
Napisz funkcje, która otrzymuje cztery argumenty:
dodatnią liczbę całkowitą n oraz trzy n-elementowe tablice tab1, tab2 i tab3 o elementach typu int, i:
a. przypisuje elementom tablicy tab3 sumę odpowiadających im elementów tablic tab1 i tab2
(do komórki tablicy tab3 o indeksie i powinna trafić suma elementów tab1[i] i tab2[i]),
b. przypisuje elementom tablicy tab3 większy spośród odpowiadających im elementów tablic tab1 i tab2
(do komórki tablicy tab3 o indeksie i powinien trafić większy spośród elementów tab1[i] i tab2[i]),
c. przypisuje zawartość tablicy tab1 do tablicy tab2, zawartość tablicy tab2 do tablicy tab3
oraz zawartość tablicy tab3 do tablicy tab1.
 */

#include <iostream>

using namespace std;

//Wyswietlanie wynikow dla testow
void display_tab(int n, int tab1[], int tab2[], int tab3[]){
    for(int i = 0; i < n; i++){
        printf("Indeks %d --> tab1: %d tab2: %d tab3: %d \n", i, tab1[i], tab2[i], tab3[i]);
    }
    cout << endl;
}


void my_function(int n, int tab1[], int tab2[], int tab3[]){
    //a) Przypisanie tablicy sumy elementow z pozostalych tablic
    for(int i =0 ; i < n; i++){
        tab3[i] = tab1[i] + tab2[i];
    }

    cout << "tab1 + tab2 = tab3" << endl;
    display_tab(n,tab1,tab2,tab3);

    //b) Porownanie i przypisanie wiekszej wartosci
    for(int i = 0; i < n; i++){
        if(tab1[i] > tab2[i])
            tab3[i] = tab1[i];
        else
            tab3[i] = tab2[i]; //Jeżeli są rowne nie ma znaczenia ktory element przypisze
    }

    cout << "tab3 > z tab1 i tab2" << endl;
    display_tab(n,tab1,tab2,tab3);

    // c) Przypisywanie zawartosci tablicy
    for(int i = 0; i < n; i++){
        int s = 0;
        s = tab1[i]; //Zawartosc tab1 do schowka
        tab1[i] = tab3[i];
        tab3[i] = tab2[i];
        tab2[i] = s;

    }

    cout << "Przypisanie wartosci" << endl;
    display_tab(n,tab1,tab2,tab3);
}


int main() {

    int tab1[2] = {1,2};
    int tab2[2] = {3,4};
    int tab3[2] = {5,6};

my_function(2,tab1,tab2,tab3);

    return 0;
}