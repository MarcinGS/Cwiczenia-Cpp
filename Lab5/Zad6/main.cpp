/********************************************************************************************************************
*6. Napisać funkcję ze zmienną liczbą argumentów, która dla podanych jako parametry wartości typu String zwróci ten,*
*który jest pierwszy w kolejności alfabetycznej.                                                                    *
********************************************************************************************************************/

#include <iostream>
#include <cstdarg>

using namespace std;

string firstString(int n, ...) {

    string input,   //Wczytywany argument
           result;

    va_list ap;
    va_start(ap, n);

    result = va_arg(ap, char*);     //Wczytanie pierwszego argumentu

    //Porównywanie kolejnych argumentow
    for (int i = 0; i < (n - 1); i++) {
        input = va_arg(ap, char*);

        //Przypisanie wynikowi aktualnego wyrazu
        if(input < result)
            result = input;
    }
    va_end(ap);
    return result;
}

int main() {
   string word;
   word = firstString(3,"adc","ad","abcd");
   cout << word;
    return 0;
}