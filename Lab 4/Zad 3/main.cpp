/******************************************************************************************************
* 3. Napisz funkcję palindrom sprawdzającą, czy dany łańcuch typu string zapisany w pliku tekstowym,  *
* którego nazwa jest przekazywana jako parametr do funkcji, jest palindromem.                         *
* Palindrom to napis, który czytany po literce od tyłu jest taki sam, jak czytany od przodu.          *
* Przy tym znaczenie maja tylko występujące w napisie litery, zaś pozostałe znaki,                    *
* jak cyfry, znaki interpunkcyjne i znaki białe, są ignorowane.                                       *
* Poza tym nie ma znaczenia wielkość liter.                                                           *
* Na przykład palindromem jest zdanie Ile Roman ładny dyndał na moreli.                               *
*******************************************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

//Zmodyfikowana funkcja sprawdzajaca palindrom z zadan laboratoriow 1
bool palindrom_check(string fileName){

    string input;

    ifstream file (fileName, ios::in);
    if(file) {
        getline(file, input);
        cout << input << endl;
    }
    else {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return 0;
    }

    transform( input.begin(), input.end(), input.begin(),::tolower ); //Zamiana wszystkich liter na male

    //Petla usowajaca biale znaki, interpunkcyjne, oraz cyfry
    // aktualizuje index i o 1 wstecz eliminując efekt funkcji erase
    int i = 0;
    while(i < input.size()){
        if(isspace(input[i])) {
            input.erase(i, 1);
            i -= 1;
        }
        if(ispunct(input[i]) ) {
            input.erase(i, 1);
            i -= 1;
        }
        if(isdigit(input[i])) {
            input.erase(i, 1);
            i -= 1;
        }
        i++;
    }

    //Sprawdzanie czy zawartosc jest palindromem
    for(int i = 0, j = (input.size()-1); i <= j ;i++, j--){

        if(input[i] != input[j]) {
            cout << input[i] << ">" << input[j] << endl;
            cout << "Tekst nie jest palindromem";
            break;
        }
        if (i >= j)
            cout << "Tekst jest palindromem";
    }
    file.close();
    return 0;
}



int main() {


    palindrom_check("palindrom.txt");
    return 0;
}