/*********************************************************
* 9. Zaimplementuj Szyfr Cezara: kodowanie i dekodowanie *
*********************************************************/
#include <iostream>
#include <algorithm>

using namespace std;

char *koduj() {
    string input;
    int key = 0;

    cout << "Wprowadz informacje do zakodowania: ";
    getline(cin, input);
    cout << "Podaj kod szyfru od -26 liter w LEWO do 26 liter w PRAWO :" << endl;
    cin >> key;

    transform(input.begin(), input.end(), input.begin(), ::tolower);   //Zmiana wszystkiego na male litery

    //Przepisuje string do tablicy char
    char *pinput = new char[input.length()];
    int i = 0;
    for (; i < input.length(); i++) {
        *(pinput + i) = input[i];
    }
    *(pinput + i) = '\0';

    if (key >= -26 && key <= 26) {
        if (key >= 0)
            //Dla kazdej litery tekstu
            for (int j = 0; j < i; j++) {
                if (*(pinput + j) + key <= 'z')     //Jezeli przesuniecie miesci sie w zakresie alfabetu (ASCII)
                    *(pinput + j) += key;
                else
                    *(pinput + j) += (key - 26);    //Jezeli wychodzi poza zakres (poza Z) odejmujemy 26 pozycji
            }
        else
            for (int j = 0; j < i; j++) {
                if (*(pinput + j) + key >= 'a')
                    *(pinput + j) += key;
                else
                    *(pinput + j) += (key + 26);
            }
    }
    return pinput;
}
int main() {

    cout << koduj();
    return 0;
}
