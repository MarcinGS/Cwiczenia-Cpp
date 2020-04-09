/**********************************************************************************************************
 * Napisz funkcję char *strat(char *tekst_1, char *tekst_2)                                               *
 * dodającą do łańcucha tekst_1 łańcuch tekst_2, funkcja ma zwracać wskaźnik na połączony łańcuch tekst_1.*
 *********************************************************************************************************/

#include <iostream>

using namespace std;

char *strat(char *tekst1, char *tekst2) {

    int t1_length = 0,  //Dlugosc tekstu 1
        t2_length = 0;  //Dlugosc tekstu 2

        //Liczenie dlugosci obu tablic
    while (*(tekst1 + t1_length) != '\0')
        t1_length++;

    while (*(tekst2 + t2_length) != '\0')
        t2_length++;


    //Sprawdzanie czy pierwsza tablica pomiesci oba ciagi
    if(sizeof(tekst1) >= (t1_length + t2_length)+1){

        char *ptr_t2 = tekst2; //wskaznik na poczatek drugiej tablicy

        while((*(tekst1 + t1_length) = *ptr_t2) != '\0'){   //kopiuje druga tablice do pierwszej do znaku \0
            t1_length++;
            ptr_t2++;
        }
        *(tekst1 + t1_length) = '\0'; //Dodawanie znaku konca
        ptr_t2 = nullptr;
        return tekst1;

    }
    //Jeżeli pierwsza tablica nie pomieści calego ciagu
    else {

        char *ptab = new char[(t1_length + t2_length)+1]; //Tworzenie toblicy o odpowiednim rozmiarze

        //Kopiowanie pierwszej tablicy
        int i = 0;
        while((*(ptab + i) = *(tekst1 + i)) != '\0'){
            i++;
        }
        //Kopiowanie drugiej tablicy
        while((*(ptab + i) = *(tekst2)) != '\0'){
            i++;
            tekst2++;
        }

        *(ptab + i) = '\0'; //Dodawanie znaku konca lini

        return ptab;
    }

}

int main() {

    char text1[] = {"abcd"};
    char text2[] = {"efgh"};
    cout << strat(text1,text2);

    return 0;
}