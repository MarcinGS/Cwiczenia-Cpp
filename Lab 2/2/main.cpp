/********************************************************************************************************************
 * Zadanie 2                                                                                                        *
 * Napisz funkcję usun(char *tekst, char znak)                                                                      *
 * usuwającą wszystkie wystąpienia znaku podanego jako drugi parametr funkcji                                       *
 * z łańcucha tekstowego (pierwszy argument funkcji).                                                               *
 ********************************************************************************************************************/

#include <iostream>

using namespace std;

void usun(char *text, char znak){
    int i = 0;
    while(*(text + i) != '\0'){
        if(*(text+i) == znak){    //Znajduje znak
            //Usuwam znak przepisujac ciag w lewo
            int j = i;
            while(*(text + j) != '\0'){
                *(text+j) = *(text+(j+1));
                j++;
            }
            *(text+j) = '\0'; //Dodaje znak konca lini
        }
        i++;
    }
}

int main() {

    char tab[10] = {"123456789"};

    for(char i : tab ){
        cout << i;
    }

    usun(tab,'3');

    cout << endl;
    for(char i : tab ){
        cout << i;
    }
    return 0;
}
