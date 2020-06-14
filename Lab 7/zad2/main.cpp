/**********************************************************************************************
 * 2. Napisać funkcję wyliczającą pierwiastki równania kwadratowego. Program powinien pytać   *
 *   użytkownika o podanie trzech parametrów a, b oraz c. W programie należy wykorzystać      *
 *   obsługę wyjątków zabezpieczającą program przed nietypowymi sytuacjami jak: dzielnie przez*
 *   zero, pierwiastek z liczby ujemnej itp. itd.                                             *
 *********************************************************************************************/

#include <iostream>
#include <stdexcept>

using namespace std;

void rownanieKwadratowe(int a, int b, int c){
    if(a == 0)
        throw ( "Wspolczynnik \"a\" nie moze byc zerem ");
}
int main() {
    try {
        rownanieKwadratowe(0, 1, 2);
    }
    catch (const char* msg){
        cout << msg;
    }
    return 0;
}
