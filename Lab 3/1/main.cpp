/****************************************************************
* 1. Napisz funkcję char *strupr(char *t)                       *
* zamieniającą zawartość łańcucha t na duże litery,             *
* funkcja ma zwracać wskaźnik na zmodyfikowany łańcuch.         *
****************************************************************/
#include <iostream>

using namespace std;

char *strupr(char *t){
    char *ptr_t = t; //Wskaznik na pierwszą wartosc ciagu

    while(*ptr_t != '\0'){                  //Sprawdza do znaku konca ciagu
        if(*ptr_t > 64 && *ptr_t < 91)      //Jezeli mala litera(ASCII od 65 do 90)
            *ptr_t += 32;                   //Zmiana na duza (z "A" do "a" jest 32 pozycje)

        ptr_t++;                            //Wskaznik na nastepny znak w ciagu
    }
    return t;                               //Zwraca oryginalny wskaznik na zmieniona tablice
}

int main() {

    char tab[] = {"MaRciN"};
    strupr(tab);
    cout << tab;
    return 0;
}

