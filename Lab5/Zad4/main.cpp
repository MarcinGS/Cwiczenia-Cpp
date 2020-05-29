/***************************************************************************************************
*4. Napisz funkcję, która sortuje podane jako argumenty wartości rosnąco i wyświetla je na ekranie.*
***************************************************************************************************/

#include <iostream>
#include <cstdarg>

using namespace std;

void numSort(int n, ...){

    int tab[n],
        box;        //Zmienna pomocnicza do zamiany miejscami w tablicy

    va_list ap;
    va_start(ap,n);

    //Wczytywanie argumentów do tablicy
    for(int i = 0; i < n; i++){
        tab[i] = va_arg(ap,int);
    }

    va_end(ap);

    //Sortowanie przez wybor
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++){
            if(tab[j] < tab[i]){
                box = tab[i];
                tab[i] = tab[j];
                tab[j] = box;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << tab[i];
    }

}

int main() {

    numSort(5,3,2,4,5,1);
    return 0;
}