/***********************************************************************************************
 * 5. Napisz funkcję przyjmującą jako parametr nazwę pliku.                                    *
 * Funkcja ma obliczać liczbę znaków w pliku z podziałem na litery, cyfry i znaki specjalne.   *
 * W przypadku gdy plik nie istnieje lub jest pusty funkcja powinna rzucić odpowiedni wyjątek, *
 * który powinien zostać obsłużony w funkcji main()..                                          *
 **********************************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void file_char_cout(string name){
    char sign;
    int letters = 0,
    nums = 0,
    spec_char = 0;

    fstream plik;
    plik.open(name,ios::in);
    if (plik) {
        while (plik.get(sign)) {
            if (isdigit(sign))
                nums++;
            else if (isalpha(sign))
                letters++;
            else if (ispunct(sign))
                spec_char++;
        }
        plik.close();
        if (letters == 0 & nums == 0 & spec_char == 0)
            throw "Plik nie zawiera szukanych znakow";
    }
    else
    throw "Plik nie istnieje.";

    cout << "Litery: " << letters << "\nCyfry: " << nums << "\nZnaki specjalne: " << spec_char << endl;
}

int main() {

    try{
        file_char_cout("plik.txt");
    }
    catch (const char* a){
        cout << a << endl;
    }
    return 0;
}