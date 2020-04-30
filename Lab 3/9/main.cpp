/*********************************************************
* 9. Zaimplementuj Szyfr Cezara: kodowanie i dekodowanie *
*********************************************************/
#include <iostream>

using namespace std;

void koduj(char *text, int key) {

    char *pinput = text;
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
}

void odkoduj(char *text, int key){

    char *pinput = text;
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
}

int main() {

    char tekst[] = {"marcin"};

    koduj(tekst,2);
    cout << "Zakodowany tekst: " << tekst << endl;

    odkoduj(tekst,2);
    cout << "Odkodowana wiadomosc: " << tekst;

    return 0;
}
