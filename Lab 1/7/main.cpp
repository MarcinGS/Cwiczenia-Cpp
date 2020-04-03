/*Napisz funkcję, która ma trzy parametry a, b, c będące liczbami całkowitymi.
 * Wartością funkcji jest jeden, jeśli zadane liczby są liczbami pitagorejskimi oraz zero w przeciwnym wypadku.
 * Liczby pitagorejskie spełniają warunek: a*a+b*b=c*c.
 * Program ma drukować na ekranie wszystkie trójki liczb pitagorejskich z zakresu od 1 do 10.*/

#include <iostream>
#include <cmath>

using namespace std;

int pitag_numbers(int a, int b, int c){

    if ((pow(a, 2) + pow(b, 2)) == pow(c, 2))
        return 1;
    else
        return 0;
}

int main() {

    cout << "Trojki liczb Pitagorejskich z zakresu od 1 do 10" << endl;
    cout << "a*a + b*b = c*c" << endl;

    //przeglad wszystkich mozliwosci kombinacji 3 liczb z podanego zakresu
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++){
            for(int k = 1; k <= 10; k++){

                //Sprawdzenie i wyswietlenie liczb
                if(pitag_numbers(i,j,k))
                    cout << i << " + " << j << " = " << k << endl;
            }
        }
    }
    return 0;
}