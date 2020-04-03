/*Napisz program, który poprosi użytkownika o podawanie dwóch liczb tak długo,
 aż jedna z nich będzie zerem. Dla każdej pary liczb program ma wyliczyć ich średnią harmoniczną.
 Funkcja ma zwracać wynik funkcji main(), która z kolei wynik ten ma pokazać. */


#include <iostream>

using namespace std;

static double srednia_harmoniczna(double num1, double num2){
    return 2 / ((1/num1) + (1/num2));
}

int main() {

    double  numb1, //Pary liczb podawane przez użytkownika
            numb2;
    do {
        cout << endl <<"Podaj dwie niezerowe liczby:" << endl;
        cout << "Podaj pierwsza liczbe: " << endl;
        cin >> numb1;

        cout << "Podaj druga liczbe: " << endl;
        cin >> numb2;

        //Oblicza srednia jezeli numb1 i numb2 nie sa zerem + komunikat.
        if(numb1 == 0 || numb2 == 0)
            cout << "Liczba nie moze byc zerem!" << endl;
        else
            cout << "Srednia harmoniczna tych liczb to: " << srednia_harmoniczna(numb1,numb2) << endl;
    }
    while (numb1 != 0 && numb2 != 0); //Konczy program gdy jedna zmienna to zero.


    return 0;
}