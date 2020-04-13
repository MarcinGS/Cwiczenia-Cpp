/***********************************************************************************************************************
* 7. Napisać funkcję obliczającą procentową częstotliwość występowania zadanego przez użytkownika znaku w linii tekstu.*
***********************************************************************************************************************/

#include <iostream>

using namespace std;

void sign_counter(char *tab){

    char sign;
    cout << "Podaj znak do wyszukania: ";
    cin >> sign;

    int i = 0,
        y = 0;

    //Liczenie wszystkich znakow (i) i znakow szukanych (y)
    while(*(tab + i) != '\0') {
        if(*(tab + i) == sign)
            y++;
        i++;
    }

    cout << "Procentowa czestotliwosc wystepowania znaku " << sign << " to: " << (100/i) * y << "%" <<endl;

}

int main() {
    char tab[] = {"asdfghjklacdz"};
    sign_counter(tab);
    return 0;
}
