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

//Dane każdego miesiąca przechowywujemy w srukturze a roku w tablicy tych struktur
//Pole struktury inicjujemy raz na poczatku aby dopisać nazwy miesięcy w każdym elemencie

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct Month {
    string month;
    double revenue = 0;
    double cost = 0;
};

void addAllRevenues(Month[]);
void addAllCosts(Month[]);
void totalFinances(Month[]);
void minMaxFinances(Month[]);
void balanceSheet(Month[]);

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
        cout << "MENU:\n";
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
                addAllCosts(monthsArray);
                break;
            }
            case 3:{
                totalFinances(monthsArray);
                break;
            }
            case 4:{
                minMaxFinances(monthsArray);
                break;
            }
            case 5:{
                balanceSheet(monthsArray);
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

void addAllCosts(Month mArray[] ){
    //Wprowadzenie kosztow z kolejnych dwunastu miesięcy
    for(int i = 0; i < SIZE; i++){
        cout << "Podaj koszt za " << mArray[i].month << endl;
        cin >> mArray[i].cost;
    }
}

void totalFinances(Month mArray[]){
    //Wyliczenie sumarycznego przychodu, sumarycznych kosztów oraz sumarycznego dochodu
    double revenueAmount = 0,   //Suma przychodow
           costAmount = 0,      //Suma kosztow
           incomeAmount = 0;    //Sumaryczny dochod

    for(int i = 0; i < SIZE; i++){
        revenueAmount += mArray[i].revenue;
        costAmount += mArray[i].cost;
    }
    incomeAmount += (revenueAmount - costAmount);   //Dochod = przychod - koszt
    cout << "^\n^\n^";
    cout << "\nSuma przychodow: " << revenueAmount << "\nSuma kosztow: " << costAmount << endl;
    cout << "Lacznie dochod wyniosl: " << incomeAmount << endl;
    cout << "^\n^\n^\n";
}

void minMaxFinances(Month mArray[]){
// Wyznaczenie wśród wprowadzonych danych minimalnego,
// maksymalnego i średniego przychodu, kosztu i dochodu, wraz z informacją,
// w których miesiącach te wartości wystąpiły

    //Zmienne dla przychodu
    double maxRevenue = 0,
           minRevenue = mArray[0].revenue,      //Inicjalizacja pierwsza wartoscia dla porownan
           medRevenue = 0;
    string maxRevMonth,     //Miesiac wystapien danych
           minRevMonth;

    //Zmienne dla kosztow
    double maxCost = 0,
           minCost = mArray[0].cost,        //Inicjalizacja pierwsza wartoscia dla porownan
           medCost = 0;
    string maxCosMonth,     //Miesiac wystapien danych
           minCosMonth;

    //Zmienne dla dochodu
    double maxIncome = 0,
           minIncome = mArray[0].revenue - mArray[0].cost, //Inicjalizacja min dochodu pierwszym dochodem
           medIncome = 0;
    string maxIncMonth,     //Miesiac wystapien danych
           minIncMonth;

    for(int i = 0; i < SIZE; i++){
        double reInput = mArray[i].revenue;
        double CoInput = mArray[i].cost;
        double InInput = (reInput - CoInput);

        //Wyszukiwanie dla przychodow
        if(reInput >= maxRevenue) {
            maxRevenue = reInput;
            maxRevMonth = mArray[i].month;
        }
        if(reInput <= minRevenue) {
            minRevenue = reInput;
            minRevMonth = mArray[i].month;
        }
        medRevenue += reInput;

        //Wyszukiwanie dla kosztow
        if(CoInput >= maxCost) {
            maxCost = CoInput;
            maxCosMonth = mArray[i].month;
        }
        if(CoInput <= minCost) {
            minCost = CoInput;
            minCosMonth = mArray[i].month;
        }
        medCost += CoInput;

        //Wyszukiwanie dla dochodow
        if(InInput >= maxIncome) {
            maxIncome = InInput;
            maxIncMonth = mArray[i].month;
        }
        if(InInput <= minIncome) {
            minIncome = InInput;
            minIncMonth = mArray[i].month;
        }
        medIncome += InInput;
    }
    //Wyliczanie srednich, dzielone na liczbe miesiecy
    medRevenue /= SIZE;
    medCost /= SIZE;
    medIncome /= SIZE;

    printf("Minimalny przychod wyniosl: %.2f w miesiacu: %s \n" ,minRevenue, minRevMonth.c_str());
    printf("Maksymalny przychod wyniosl: %.2f w miesiacu: %s \n" ,maxRevenue, maxRevMonth.c_str());
    printf("Sredni przychod wyniosl: %.2f\n\n" ,medRevenue);

    printf("Minimalny koszt wyniosl: %.2f w miesiacu: %s \n" ,minCost, minCosMonth.c_str());
    printf("Maksymalny koszt wyniosl: %.2f w miesiacu: %s \n" ,maxCost, maxCosMonth.c_str());
    printf("Sredni koszt wyniosl: %.2f\n\n" ,medCost);

    printf("Minimalny dochod wyniosl: %.2f w miesiacu: %s \n" ,minIncome, minIncMonth.c_str());
    printf("Maksymalny dochod wyniosl: %.2f w miesiacu: %s \n" ,maxIncome, maxIncMonth.c_str());
    printf("Sredni dochod wyniosl: %.2f\n\n" ,medIncome);
}

void balanceSheet(Month mArray[]){
  //  bilans dla kolejnych miesięcy: program wyświetla cztery kolumny, w pierwszej wartość przychodu,
  //  w drugiej wartość kosztu, w trzeciej wartość dochodu, w czwartej odpowiednio napisy „strata”, „zysk” lub „zero”
  //  w zależności od relacji pomiędzy przychodem a kosztem.
  //  Każdy wiersz zawiera dane z jednego miesiąca.

    printf("%-11s   %10s   %10s   %10s\n","Miesiac", "Przychod", "Koszt", "Dochod");

    //Wyświetla dane każdego miesiąca w kazdej iteracji
    for(int i = 0; i < SIZE; i++) {
        double cost = mArray[i].revenue-mArray[i].cost; //Obliczanie dochodu
        string flag;

        //Ustalanie flagi w tabeli wedlug obliczonego dochodu
        if(cost < 0)
            flag = "STRATA";
        else if (cost == 0)
            flag = "ZERO";
        else
            flag = "ZYSK";
        //Wyświetlenie wynikow każdego miesiaca
        printf("%-11s   %10.2f   %10.2f   %10.2f   %-10s\n",mArray[i].month.c_str(),mArray[i].revenue, mArray[i].cost, cost, flag.c_str());
    }

}
