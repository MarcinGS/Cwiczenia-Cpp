/********************************************************************************************************************
* 2. Napisz program definiujący zmienną typu TData (struktura) oraz wskaźnik do zmiennej typu TData.                *
* Napisz funkcję która jako parametr przyjmuje wskaźnik do struktury i wczytuje z klawiatury wartości pól zmiennej. *
* Zastosuj wskaźnik i operator adresu (nie stosuj operatora new).                                                   *
********************************************************************************************************************/

#include <iostream>

using namespace std;

struct TData{
    int poleInt;
    string poleString;
};

//Przypisuje dane wczytane z klawiatury polom zmiennej strukturalnej
void my_function(TData *s){
    cout << "Podaj Int :";
    cin >> s->poleInt;

    cout << "Podaj String :";
    cin >> s->poleString;
}

int main() {

    TData zmienna;  //Inicjacja zmiennej strukturalnej
    TData *ptrTdata = &zmienna; //Wskaznik na adres zmiennej

    my_function(ptrTdata);

    cout << zmienna.poleString << " " << zmienna.poleInt << endl;

    return 0;
}

