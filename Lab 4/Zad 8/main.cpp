/*************************************************************************************************************************************
* 8. Napisz funkcje, która wywoływana jest z dwoma argumentami. Pierwszy to wskaźnik do tablicy znaków, drugi to rozmiar tej tablicy.*
* Funkcja ta ma do początku bieżącej treści tablicy znaków dopisać tekst "UWAGA:".                                                   *
* Jeśli w rezultacie powstałby łańcuch dłuższy, niż na to pozwala obecny rozmiar tablicy znaków -                                    *
* niech trzy ostatnie możliwe znaki zostaną zastąpione trzema kropkami.                                                              *
* Jako rezultat swej pracy funkcja ta ma zwracać wskaźnik do tablicy znaków, na której dokonała zmiany.                              *
*************************************************************************************************************************************/


#include <iostream>

using namespace std;

char *uwaga_func(char *tab, int size) {

    char uwaga_tab[7] = "UWAGA:";
    char dots[4] = "...";
    char *ptr_tab = tab;


    int i = 0;
    while (*(ptr_tab + i) != '\0') {
        i++;
    }

    if (size >= (i + 7)) {
        char copy_tab[size];

        //Kopiuje UWAGA
        int j = 0;
        while ((copy_tab[j] = uwaga_tab[j]) != '\0')
            j++;

        //Kopiuje tekst oryginalnej tablicy
        for (int k = 0; *(ptr_tab + k) != '\0'; k++, j++)
            copy_tab[j] = *(ptr_tab + k);

        //Zapisanie gotowej tablicy
        for (int k = 0; copy_tab[k] != '\0'; k++)
            *(ptr_tab + k) = copy_tab[k];

    }
    else {
        char copy_tab[size];

        //Kopiuje UWAGA
        int j = 0;
        while (uwaga_tab[j] != '\0') {
            copy_tab[j] = uwaga_tab[j];
            j++;
        }

        //Kopiuje tekst oryginalnej tablicy
        int k = 0;
        while(j<=(size-2)) {
            copy_tab[j] = *(ptr_tab + k);
            j++;
            k++;
        }

        copy_tab[j] = '\0'; //Dodaje znak konca lini
        j--;

        //Wpisuje 3 kropki od konca
        for (int l = 0; dots[l] != '\0'; l++, j--)
            copy_tab[j] = dots[l];

        //Zapisanie gotowej tablicy
        int l = 0;
        for (; copy_tab[l] != '\0'; l++)
            *(ptr_tab + l) = copy_tab[l];
        l++;
        *(ptr_tab + l) = '\0';
    }
    return tab;
}

int main() {

    char tab[12] = "slisko";
    uwaga_func(tab,12);
    cout << tab;
    return 0;
}
