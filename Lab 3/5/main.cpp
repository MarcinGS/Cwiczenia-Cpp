/*******************************************************************************************
* 5. Napisz funkcję char *reverse(char *t)                                                 *
* odwracającą kolejność wystąpienia znaków w łańcuchu t                                    *
* (ostatni znak staje się pierwszy itd.). Funkcja ma zwracać wskaźnik na zamieniony tekst. *
*******************************************************************************************/

#include <iostream>

using namespace std;

char *reverse(char *t){
    char *p_front_tab = t;                      //Wskaznik na poczatek tablicy

    //Liczy dlugosc ciagu
    int i = 0;
    while( *(p_front_tab + i) != '\0'){
        i++;
    }

    char *p_rear_tab = (p_front_tab + (i-1));   //Wskaznik na koniec tablicy

    char box;      //Zmienna pomocnicza

    //Zamiana znakow miejscami
    for( ; p_front_tab < p_rear_tab; p_front_tab++, p_rear_tab--){
        box = *(p_front_tab);
        *(p_front_tab) = *(p_rear_tab);
        *(p_rear_tab) = box;
    }

    p_front_tab = nullptr;
    p_rear_tab = nullptr;
    return t;
}

int main() {

    char tab[] = {"Marcin"};

    cout << tab << endl;
    reverse(tab);
    cout << tab << endl;

    return 0;
}
