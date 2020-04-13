/****************************************************************
* 2. Napisz funkcję char *strlwr(char *t)                       *
* zamieniającą zawartość łańcucha t na małe litery, funkcja     *
* ma zwracać wskaźnik na zmodyfikowany łańcuch.                 *
****************************************************************/


#include <iostream>

using namespace std;

char *strlwr(char *t){
    char *ptr_t = t; //Wskaznik na pierwszą wartosc ciagu

    while(*ptr_t != '\0'){                  //Sprawdza do znaku konca ciagu
        if(*ptr_t > 64 && *ptr_t < 91)      //Jezeli duza litera(ASCII od 65 do 90)
            *ptr_t += 32;                   //Zmiana na mala (z "A" do "a" jest 32 pozycje)

        ptr_t++;                            //Wskaznik na nastepny znak w ciagu
    }
    return t;                               //Zwraca oryginalny wskaznik na zmieniona tablice
}

int main() {
    char tab[] = {"MaRciN"};
    strlwr(tab);
    cout << tab;
    return 0;
}