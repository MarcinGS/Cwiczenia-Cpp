/********************************************************************************************************************
 * Zadanie 3                                                                                                        *
 * Napisz funkcję strcmp ( char ∗tekst_1, char ∗tekst_2 ),                                                          *
 * porównującą dwa łańcuchy tekstowe. Funkcja ma zwrócić wartośc true jeżeli podane łańcuchy są takie same,         *
 * lub wartość false, gdy się różnią.                                                                               *
 ********************************************************************************************************************/

#include <iostream>

using namespace std;

bool strcmp(char *tekst_1, char *tekst_2){

}

int main() {

    char text1[] = {"abcdefg"};
    char text2[] = {"abclef"};

    cout << strcmp(text1,text2) << "<== Zwraca " ;
    return 0;
}
