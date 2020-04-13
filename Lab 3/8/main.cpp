/**************************************************************************************************************
* 8. Napisz funkcję wczytującą łańcuch znaków, funkcja ma zliczać liczbę podanych znaków.                     *
* Funkcja powinna zwrócić informacje: - ile było podanych znaków, oraz ile z tych znaków było dużymi literami.*
**************************************************************************************************************/

#include <iostream>

using namespace std;

void how_many_is_upper(){

    int char_sum = 0,       //Suma znakow
        upper_letters = 0;  //Suma duzych liter

    //Pobranie danych od uzytkownika
    string input;
    cout << "Podaj lancuch znakow: ";
    getline(cin,input);

    char *pinput = new char[input.length() + 1];     //Tworzy robocza tablice char o dlugosci "input" +1

    //Wpisywanie wartosci string do roboczej tablicy char
    for(; char_sum < input.length(); char_sum++){
        *(pinput + char_sum) = input[char_sum];
    }
    *(pinput + char_sum) = '\0';                       //Dodanie znaku konca ciagu

    //Liczy liczbe duzych liter
    int i = 0;
    while(*(pinput + i) != '\0') {
        if (*(pinput + i) > 64 && *(pinput + i) < 91) {         //Jezeli duza litera(ASCII od 65 do 90)
            upper_letters++;
        }
        i++;
    }

    cout << "Podano " << char_sum << " znakow." << endl;
    cout << upper_letters << " z tych znakow bylo duzymi literami." << endl;

    delete [] pinput;
}
int main() {
    how_many_is_upper();
    return 0;
}
