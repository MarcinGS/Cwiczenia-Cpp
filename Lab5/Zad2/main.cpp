/******************************************************************************************************
 * 2. Napisz funkcję ze zmienną liczbą argumentów, która przyjmuje dowolną liczbę łańcuchów,          *
 * a w rezultacie zwraca połączony łańcuch składający się z łańcuchów podanych jako argumenty,        *
 * oddzielonych przecinkiem, pomijając łańcuchy zaczynające się od litery -a-.                        *
 * Pierwszym argumentem funkcji jest liczba łańcuchów do podania w argumentach funkcji-s.             *
 * Łańcuchy mają być wprowadzane z klawiatury.                                                        *
 *****************************************************************************************************/


#include <iostream>
#include <cstdarg>

using namespace std;

string textLinking(int n, ...){

    string  text;
    char *input;

    va_list ap;
    va_start(ap, n);

    for(int i = 0; i< n; i++) {
        input = va_arg(ap,char*);   //Wczytywanie argumentów

        //Nie połączy napisów jeżeli zaczynają sie na A
        if( !(input[0] == 'a' || input[0] == 'A') )  {
            text += input;
            text += ",";
        }
    }
    va_end(ap);

    return text;
}

int main() {

string result;

result = textLinking(2, "raz","dwa");
cout << result << endl;
    return 0;
}