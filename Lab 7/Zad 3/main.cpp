/***********************************************************************************************************
 * 3. Napisać program, w którym zostaną zaimplementowane własne klasy wyjątków.                            *
 * Klasy te należy wykorzystać do obsługi wyjątków w programie wyliczającym następujący wzór matematyczny: *
 * Należy zaprezentować działanie tak stworzonych klas dla różnych rodzajów danych wejściowych.            *                                 *
 **********************************************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

class DzieleniePrzeZzero{
public:
    string blad = "Nie wolno dzielic przez zero";
};

class UjemnyPierwiastek{
public:
    string blad = "Liczba ujemna pod pierwiastkiem";
};

double policz(){
    int a,b;

    cout << "Podaj wartosc \"a\" ulamka" << endl;
    cin >> a;
    if(a < 0) throw UjemnyPierwiastek();
    cout << "Podaj wartosc \"b\" ulamka" << endl;
    cin >> b;
    if (b == 0) throw DzieleniePrzeZzero();

    return sqrt(a) / b;
}
int main() {

    double wynik;

    try{
        wynik = policz();
        cout << "Wynik: " << wynik << endl;
    }
    catch (UjemnyPierwiastek a){
        cout << a.blad << endl;
    }
    catch (DzieleniePrzeZzero a){
        cout << a.blad << endl;
    }

    return 0;
}