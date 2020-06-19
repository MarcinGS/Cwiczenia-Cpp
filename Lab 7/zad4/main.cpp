/**********************************************************************************************
 * 4. Napisz funkcję PESEL, która przyjmuje ciąg znaków będących numerem PESEL,               *
 * która sprawdza czy PESEL jest poprawny według algorytmu                                    *
 * (można skorzystać np. z Wikipedii https://pl.wikipedia.org/wiki/PESEL).                    *
 * Jeśli przekazany PESEL nie jest poprawny, program powinien wyrzucać wyjątek.               *
 * Napisz funkcję main i przetestuj program.                                                  *
 *********************************************************************************************/


#include <iostream>

using namespace std;

void pesel_check(){

    string pesel;
    int pesel_tab[11];
    int kod[4] = {9,7,3,1};
    int suma = 0;

    cout << "Podaj nr pesel" << endl;
    cin >> pesel;
    if(pesel.size() != 11)
        throw "Nieodpowiednia ilosc cyfr. Powinno byc 11";

    //kopiowanie pesel do tablicy
    // (-48) ---char na int
    for(int i = 0; i < 11; i++){
     pesel_tab[i] = (pesel[i] - 48);
    }

    //Mnożenie kolejnych cyfr pesel wedlug kodu sprawdzania 9 7 3 1
    int j = 0;
    for(int i = 0; i < 10; i++){
        suma += (pesel_tab[i] * kod[j]);
        j++;
        if (j > 3)
            j = 0;
    }

    if((suma%10) != pesel_tab[10])
        throw "PESEL nie jest poprawny";
    else
        cout << "PEEL poprawny.";
}
int main() {

    try{
        pesel_check();
    }
    catch(const char* a){
        cout << a << endl;
    }
    return 0;
}