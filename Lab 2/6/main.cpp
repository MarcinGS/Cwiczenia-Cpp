/******************************************************************************************************
 * 6. Napisz funkcję int strchr(char *tekst, char znak)                                               *
 * zwracającą indeks pierwszego wystąpienia zadanego znaku w łańcuchu znaków.                         *
 * Zmodyfikuj funkcję tak, aby zwracała wskaźnik na pierwsze wystąpienie zadanego znaku w tekście.    *
 * (jeżeli znak nie występuje w tekście funkcja powinna zwrócić wartość NULL)                         *
 * ***************************************************************************************************/

#include <iostream>

using namespace std;

int strchr(char *tekst, char znak){
    int i = 0;
    while(*(tekst+i) != znak){ //Szukanie znaku
        i++;
    }
    return i;
}


const char *strchr(char const *tekst, char znak) {
    char const *ptr = nullptr;

    ptr = tekst;
    while (*ptr != '\0') { //Przeszukianie takstu do konca
        if (*ptr == znak) {
            return ptr; //Zwraca wskaznik jak znajdzie szukany znak
        }
        ptr++;
    }
    ptr = nullptr;
    return ptr; //Jesli znak nie wystapi znak zwraca wyzerowany wskaznik
}

int main() {

    char tab[] = {"abcdc"}; //Tablica dla 1 funkcji
    char const tab2[] = {"abcd"}; //Tablica dla przeciążonej funkcji

    cout << strchr(tab,'c') << endl;

    char const *pznak = strchr(tab2,'e');
    cout << *pznak;
    pznak = nullptr;

    return 0;
}