/**********************************************************************************************
* 6. Napisać funkcję, która wykonuje zadaną przez użytkownika operację arytmetyczną w postaci *
* „x □ y” (podaną jako tekst), gdzie x, y są liczbami, zaś □ jest jednym ze znaków +, -, *, /.*
**********************************************************************************************/

#include <iostream>
#include <cmath>
#include <string>


using namespace std;

void calc(){
    string input;   //Zmienna na dane wejsciowe od uzytkownika
    float x = 0,    //Piersza liczba
          y = 0;    //Druga liczba
    char sign;      //Znak operacji

    cout << "Wpisz jakie zadanie wykonac: ";
    getline(cin,input);

    int tab_length = input.length(); //Sprawdzamy slugosc wprowadzonego tekstu
    char *inp_tab =  new char[tab_length + 1]; //Rezerwujemy pamiec na tablice char wielkosci string-a

    int i = 0; //Iteracja wskazujaca pozycje na ktorej wykonuje operacje

    //Kopiowanie danych do tablicy char
    for( i = 0; i < tab_length; i++){
        *(inp_tab + i) = input[i];
    }
    *(inp_tab + i) = '\0'; //Dodanie znaku konca ciagu

    i--; //cofamy indeks ze znalu \0 na ostatnia wartosc

    //Wczytuje do zmiennej y druga liczbe dzialania
    for(int j = 0; i >= 0; i--, j ++){

        if(*(inp_tab + i) >= '0' && *(inp_tab + i) <= '9') {  //Jezeli wskazywany znak jest znakiem cyfry

            //Zamiana znaku char na wartosc int odejmujac znak '0' czyli 48 (ASCII)
            //Example:
            // '1' to 49 jak odejme 48 zostanie 1
            // '3' to 51 jak odejme 48 zostanie 3
            int number = *(inp_tab + i) - '0';

            //Sumowanie wartości cyfr wagami od konca do znaku dzialania
            //Example:
            //234 = (4*10^0) + (3*10^1) + (2*10^2)
            y += number * (pow(10, j));
        }
        else {
            //Jezeli nie cyfra iterator natrafil na znak
            sign = *(inp_tab + i);
            break; //Przerwanie petli znak oznacza kolejna liczbe
        }
    }

    i--; //Cofamy iterator ze znaku dzialania na kolejna liczbe

    //Takiesame operacje co powyzej
    for(int j = 0; i >= 0; i--, j ++) {
        if (*(inp_tab + i) >= '0' && *(inp_tab + i) <= '9') {
            int number = *(inp_tab + i) - '0';
            x += number * (pow(10, j));
        }
    }

    switch (sign){
        case '+' :
            cout << x << " " << "+" << " " << y << " = " << (x+y);
            break;
        case '-':
            cout << x << " " << "-" << " " << y << " = " << (x-y);
            break;
        case '*':
            cout << x << " " << "*" << " " << y << " = " << (x*y);
            break;
        case '/':
            cout << x << " " << "/" << " " << y << " = " << (x/y);
            break;
        default:
            cout << "Nieobslugiwany znak";
    }
    delete [] inp_tab;
}
int main() {

    calc();
    return 0;
}
