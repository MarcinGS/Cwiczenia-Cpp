/************************************************************************************
* 3. Napisz funkcję char *strch(char *t)                                            *
* zamieniającą zawartość łańcucha t z małych liter na duże,                         *
* a z dużych na małe litery, funkcja ma zwracać wskaźnik na zmodyfikowany łańcuch.  *
************************************************************************************/

#include <iostream>

using namespace std;

char *strch(char *t){

    char *ptr_t = t; //Wskaznik na pierwszą wartosc ciagu

    while(*ptr_t != '\0'){                      //Sprawdza do znaku konca ciagu

        if(*ptr_t > 64 && *ptr_t < 91)          //Jezeli duza litera(ASCII od 65 do 90)
            *ptr_t += 32;                       //Zmiana na mala (z "A" do "a" jest 32 pozycje)

        else if (*ptr_t > 96 && *ptr_t < 123)   //Jezeli mala litera(ASCII od 97 do 122)
            *ptr_t -= 32;                       //Zmiana na duza

        ptr_t++;                                //Wskaznik na nastepny znak w ciagu
    }
    return t;                                   //Zwraca oryginalny wskaznik na zmieniona tablice
}

int main() {

    char tab[] = {"MaRciN"};
    strch(tab);
    cout << tab;
    return 0;
}
