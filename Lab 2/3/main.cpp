/********************************************************************************************************************
 * Zadanie 3                                                                                                        *
 * Napisz funkcję strcmp ( char ∗tekst_1, char ∗tekst_2 ),                                                          *
 * porównującą dwa łańcuchy tekstowe. Funkcja ma zwrócić wartośc true jeżeli podane łańcuchy są takie same,         *
 * lub wartość false, gdy się różnią.                                                                               *
 ********************************************************************************************************************/

#include <iostream>

using namespace std;

bool strcmp(char *tekst_1, char *tekst_2){

    //Wykonuje poki znaki sa takiesame
    while(*tekst_1 == *tekst_2){

        //Zwraca true jak osiagnie znak konca ciagu
        if(*tekst_1 == '\0')
            return true;

            //Jezeli nie wskaznik na kolejny znak
            tekst_1++;
            tekst_2++;
    }
    return false;

}

int main() {

    char text1[] = {"abcde"};
    char text2[] = {"abcde"};

    cout << strcmp(text1,text2) << "<== Zwraca " ;
    return 0;
}
