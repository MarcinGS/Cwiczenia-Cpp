/*******************************************************************************************************************
* 6. Napisz funkcję wczytujący dowolny plik tekstowy, następnie funkcja ma zakodować plik za pomocą szyfru Cezara  *
* i zapisać wynik do innego pliku (funkcja przyjmuje dwa parametry nazwę pliku tekstowego, oraz przesunięcie).     *
* Napisz drugą funkcję dekodującą dowolny plik tekstowy.                                                           *
* *****************************************************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void szyfruj (string, int);
void odszyfruj(string, int);

int main() {

    szyfruj("nowy.txt",1);
    odszyfruj("Zaszyfrowany.txt", 1);
    return 0;
}

void szyfruj (string plik, int key){

    const int MAX_SIZE = 256;
    char tekst[MAX_SIZE];    //Tablica na szyfrowany tekst

    fstream infile;
    infile.open(plik, ios::in);   //Otwarcie pliku do odczytu

    fstream outfile;                                            //Otwarcie pliku do zapisu badz dopisu dla tresci
    outfile.open("Zaszyfrowany.txt", ios::out|ios::app);     //wiekszych niz 256 znakow

    //Wczytywanie i zapisywanie tresci pliku
    if(infile){
        while(!infile.eof()) {

            infile.getline(tekst, 256); //Wczytywanie liniami po 256 znakow

            //Szyfrowanie podanej tablicy
            char *pinput = tekst;
            int i = 0;
            while(*(pinput + i) != '\0')
                i++;

            if (key >= -26 && key <= 26) {
                if (key >= 0)                               //Dla dodatnich pozycji
                    //Dla kazdej litery tekstu
                    for (int j = 0; j < i; j++) {
                        if (*(pinput + j) + key <= 'z')     //Jezeli przesuniecie miesci sie w zakresie alfabetu (ASCII)
                            *(pinput + j) += key;
                        else
                            *(pinput + j) += (key - 26);    //Jezeli wychodzi poza zakres (poza Z) odejmujemy 26 pozycji
                    }
                else                                        //Dla ujemnych pozycji
                    for (int j = 0; j < i; j++) {
                        if (*(pinput + j) + key >= 'a')     //Jezeli miejsci sie w zakresie
                            *(pinput + j) += key;
                        else
                            *(pinput + j) += (key + 26);    //Jezeli nie to dodajemy 26 pozycji
                    }
            }
            outfile << tekst;   //Dopisywanie zaszyfrowanej tresci
        }
        infile.close();
        outfile.close();
    }
    else{
        cout << "Blad otwarcia pliku";
    }
}


void odszyfruj (string plik, int key){

    const int MAX_SIZE = 256;
    char tekst[MAX_SIZE];    //Tablica na zaszyfrowany tekst

    fstream infile;
    infile.open(plik, ios::in);   //Otwarcie pliku do odczytu

    fstream outfile;                                            //Otwarcie pliku do zapisu badz dopisu dla tresci
    outfile.open("Odszyfrowany.txt", ios::out|ios::app);     //wiekszych niz 256 znakow

    //Wczytywanie i zapisywanie tresci pliku
    if(infile){
        while(!infile.eof()) {

            infile.getline(tekst, 256); //Wczytywanie liniami po 256 znakow

            //Odszyfrowanie podanej tablicy
            char *pinput = tekst;
            int i = 0;
            while(*(pinput + i) != '\0')
                i++;

            if (key >= -26 && key <= 26) {
                if (key >= 0)
                    for (int j = 0; j < i; j++) {
                        if (*(pinput + j) - key <= 'z')
                            *(pinput + j) -= key;
                        else
                            *(pinput + j) += (key + 26);
                    }
                else
                    for (int j = 0; j < i; j++) {
                        if (*(pinput + j) + key >= 'a')
                            *(pinput + j) += key;
                        else
                            *(pinput + j) += (key - 26);
                    }
            }
            outfile << tekst;   //Dopisywanie odszyfrowanej tresci
        }
        infile.close();
        outfile.close();
    }
    else{
        cout << "Blad otwarcia pliku";
    }
}

