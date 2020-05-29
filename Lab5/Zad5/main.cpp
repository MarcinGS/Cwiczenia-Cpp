/******************************************************************************************************************
*5. Program Roczny bilans: napisać program pozwalający na przeprowadzenie rocznego bilansu dochodów               *
*związanych z prowadzeniem działalności gospodarczej. Przedsiębiorca w każdym miesiącu osiąga przychód,           *
*aby go osiągnąć ponosi też koszty. Różnica pomiędzy przychodem a kosztem jego uzyskania może być ujemna,         *
*wtedy przedsiębiorca ponosi stratę. Jeżeli różnica ta jest nieujemna to osiąga on dochód, być może zerowy.       *
*Zadaniem programu będzie umożliwienie przedsiębiorcy analizy rocznych przychodów, kosztów i dochodów.            *
*Wymagania użytkowe: program powiem wyświetlać proste konsolowe menu,                                             *
*pozwalające użytkownikowi na (każda funkcjonalność jako osobna funkcja):                                         *
*- wprowadzenie przychodów z kolejnych dwunastu miesięcy,                                                         *
*- wprowadzenie kosztów z kolejnych dwunastu miesięcy,                                                            *
*- wyliczenie sumarycznego przychodu, sumarycznych kosztów oraz sumarycznego dochodu,                             *
*- wyznaczenie wśród wprowadzonych danych minimalnego,                                                            *
*  maksymalnego i średniego przychodu, kosztu i dochodu, wraz z informacją,                                       *
*  w których miesiącach te wartości wystąpiły.                                                                    *
*- bilans dla kolejnych miesięcy: program wyświetla cztery kolumny, w pierwszej wartość przychodu,                *
*  w drugiej wartość kosztu, w trzeciej wartość dochodu, w czwartej odpowiednio napisy „strata”, „zysk” lub „zero”*
*  w zależności od relacji pomiędzy przychodem a kosztem.                                                         *
*Każdy wiersz zawiera dane z jednego miesiąca.                                                                    *
******************************************************************************************************************/
#include <iostream>

using namespace std;

struct Month {
    string month;
    double revenue = 0;
    double cost = 0;
};

void addAllRevenues(Month[]);
void addAllCosts();
void totalFinances();
void minMaxFinances();
void balanceSheet();

const int SIZE = 12;
const string MonthNames[SIZE] = {"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec",
                           "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};

int main() {

    int choice;
    Month monthsArray[SIZE];   //Tablica struktur

    //Inicjalizacja pola miesiaca wszystkich struktur
    for(int i = 0; i < SIZE; i++) {
        monthsArray[i].month = MonthNames[i];
    }

    cout << "PROGRAM ROCZNY BILANS" << endl;

    do{
        cout << "1 - Wprowadz przychody za caly rok.\n2 - Wprowadz koszty za caly rok." << endl;
        cout << "3 - Sumaryczne przychody, koszty oraz dochody.\n4 - Informacje o maksymalnych i minimalnych wartosciach." << endl;
        cout << "5 - Szczegulowy bilans dla wszystkich miesiecy.\n0 - Zakoncz program." << endl;
        cout << "Wybierz odpowiednia opcje:" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1: {
                addAllRevenues(monthsArray);
                break;
            }
            case 2:{
              //  addAllCosts();
                break;
            }
            case 3:{
              //  totalFinances();
                break;
            }
            case 4:{
              //  minMaxFinances();
                break;
            }
            case 5:{
             //   balanceSheet();
                break;
            }
            case 0:{
                cout << "KONIEC PROGRAMU" << endl;
            }
        }
    }
    while(choice != 0);

    return 0;
}

void addAllRevenues(Month mArray[] ){
    //Wprowadzenie przychodów z kolejnych dwunastu miesięcy
    for(int i = 0; i < SIZE; i++){
        cout << "Podaj przychod za " << mArray[i].month << endl;
        cin >> mArray[i].revenue;
    }
}