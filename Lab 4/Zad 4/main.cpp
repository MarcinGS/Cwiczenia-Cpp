#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

double total_bill(string billFile){
    char zdanie[50];     //Tablica na wczytana linie z pliku
    char tab[10];       //Tablica na skopiowana cene z wczytanej lini
    double sum = 0.0;

    ifstream file(billFile);    //Otwarcie pliku do odczytu

    if(file) {      //Jesli plik zostanie otwarty

        //Petla wczytuje linie tekstu, znajduje w niej cene
        // ktora zawsze jest na koncu lini i kopiuje do nowej tablicy
        //ktora to jest przerabiana na wartosc double [atof()]

        while(file.getline(zdanie,50)) {        //Wczytuje linie aż do konca pliku
            int i = 0;
            while(zdanie[i] != '\0')    //Przesowa iterator na koniec lini
                i++;
            while(zdanie[i] != ' ')     //Cofa iterator do poczatku ostatniego wyrazu w lini
                i--;
            i++;        //Przesowa iterator z nad spacji do pierwszego znaku wyrazu

            //Kopiuje wyraz do nowej tablicy
            int j = 0;
            while(zdanie[i] != '\0'){
                tab[j] = zdanie[i];
                j++;
                i++;
            }
            tab[j] = '\0';

            sum += atof(tab);       //Zmiana zawartosci tablicy na double

        }

    }
    else
        cout << "Blad otwarcia pliku!" << endl;

    file.close();
    return sum;
    }


int main() {

    double rachunek = total_bill("bill.txt");
    cout <<"Rachunek:" << rachunek << endl;

    return 0;
}