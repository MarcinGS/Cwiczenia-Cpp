/*Napisz funkcję, która stwierdza, czy zadana jako parametr liczba całkowita kończy się swoim pierwiastkiem.
 * Liczby kończące się swoim pierwiastkiem to 25, 625.
 * Wartością funkcji ma być jeden, jeśli liczba spełnia warunek oraz zero w przeciwnym wypadku.*/

#include <iostream>
#include <cmath>

using namespace std;

int my_function(int n){

    int dzielna = 0, //Kolejne dzielniki 10,100,1000
        ost_licz = 0; //Obliczone ostatnie cyfry / liczby podanej wartosci


    for(int i = 1; dzielna < n; i++) {

        dzielna = pow(10, i); //Liczenie kolejnych dzielnych
        ost_licz = n % dzielna; //Obliczanie kolejnych ostatnich cyfr liczby

        //Zmienne pomocnicze do testów
        //cout << "Iteracja = " << i << endl;
        //cout << "Dzielnik = " << dzielna <<endl;
        //cout << "Koncowa liczba = " << ost_licz << endl;

        //Jeżeli ost. liczba jest pierwiastkiem n
        if ((ost_licz * ost_licz) == n) {
            cout << "Zwracany wynik: " ;
            return 1;
        }
    }
            //W przeciwnym wypadku return 0
            cout << "Zwracany wynik: " ;
            return 0;
}

int main() {

cout << my_function(625);

    return 0;
}