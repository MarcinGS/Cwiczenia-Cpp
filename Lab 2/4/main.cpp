/****************************************************************************************
 * 4. Napisz funkcję strlen(char *tekst) zwracającą długość (liczbę znaków) łańcucha tekst.*
 ***************************************************************************************/


#include <iostream>

using namespace std;

int strlen(char *tekst){

    char *ptr = tekst; //Wskaznik na podana tablice
    int i = 0;  //Akumulator

    //Liczy znaki dopoki nie napotka znak konca
    while(*(ptr + i) != '\0')
        i++;

    return i;


}
int main() {

    char tab[] = {"1234"};
    cout << strlen(tab);
    return 0;
}