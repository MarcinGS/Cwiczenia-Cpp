/**************************************************************************************************
 * 7. Napisz funkcję int strrchr(char *tekst, char znak)                                          *
 * zwracającą indeks ostatniego wystąpienia zadanego znaku w łańcuchu znaków.                     *
 * Zmodyfikuj funkcję tak, aby zwracała wskaźnik na ostatnie wystąpienie zadanego znaku w tekście.*
 * (jeżeli znak nie występuje w tekście funkcja powinna zwrócić wartość NULL)                     *
 * ***********************************************************************************************/

#include <iostream>

using namespace std;

int strrchr(char *tekst, char znak){
    int i = 0;

    while(*(tekst+i) != '\0') //Przesuniecie indeksu na koniec tekstu
        i++;
    while(*(tekst+i) != znak){ //Szukanie znaku
        i--;
    }
    return i;
}

const char *strrchr(char const *tekst, char znak) {

    char const *ptr = nullptr;
    ptr = tekst;

    while (*ptr != '\0') {//Przesuniecie wskaznika do konca tekstu
        ptr++;
    }

    while (ptr >= tekst) { // >= NIE != aby sprawdzil tez wartość tekst[0]

        if (*ptr == znak)
            return ptr;
        ptr--;
    }

    ptr = nullptr;
    return ptr; //Jesli znak nie wystapi znak zwraca wyzerowany wskaznik

}


int main() {

    char tab[] = {"abcdcfg"}; //Tablica dla 1 funkcji
    char const tab2[] = {"bacd"}; //Tablica dla przeciążonej funkcji

    cout << strrchr(tab,'c') << endl;

    char const *pznak = strrchr(tab2,'b');
    cout << *pznak;
    pznak = nullptr;

    return 0;
}