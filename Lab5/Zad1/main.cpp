/******************************************************************************************************
 * 1. Napisz funkcję ze zmienną liczbą argumentów, która oblicza średnią wartość wprowadzonych liczb. *
 *****************************************************************************************************/

#include <cstdarg>
#include <cstdio>

using namespace std;

void average(int num, ...){

    double aver = 0;    //Wynik sredniej

    va_list ap;
    va_start(ap,num);   //num-ostatni obowiazkowy argument

    //Wczytywanie zmiennych typu int
    int i;
    for(i = 0; i < num; i++){
        aver += va_arg(ap, int);
    }
    aver /= i;  //Wyliczamy srednia


    printf("Srednia: %.2f", aver);

    va_end(ap);     //Porzadkowanie stosu
}
int main() {
average(3,2,3,2);
    return 0;
}