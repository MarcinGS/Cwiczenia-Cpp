/**********************************************************************************************
 * 2. Napisać funkcję wyliczającą pierwiastki równania kwadratowego. Program powinien pytać   *
 *   użytkownika o podanie trzech parametrów a, b oraz c. W programie należy wykorzystać      *
 *   obsługę wyjątków zabezpieczającą program przed nietypowymi sytuacjami jak: dzielnie przez*
 *   zero, pierwiastek z liczby ujemnej itp. itd.                                             *
 *********************************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

void rownanieKwadratowe(int a, int b, int c){
    int    delta,
           x;
    double x1,
           x2;

    if(a == 0)
        throw ( "Wspolczynnik \"a\" nie moze byc zerem ");
    else{
        delta = (b*b) - 4*(a*c);
        cout << "Delta = " << delta << endl;
    }

    if(delta > 0){
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    }
    else if (delta == 0) {
        x = -b / (2 * a);
        cout << "x: " << x << endl;
    }
    else if (delta < 0)
        throw ("Rownanie nie ma rozwiazan!");

}
int main() {
    try {
        rownanieKwadratowe(-1, 2, -3);
    }
    catch (const char* msg){
        cout << msg;
    }
    return 0;
}
