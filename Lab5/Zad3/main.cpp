/*****************************************************************************************
 * 3. Napisz funkcję maks(), która zwraca największą z podanych jako jej parametry liczb *                                                        *
 *****************************************************************************************/


#include <iostream>
#include <cstdarg>

using namespace std;

double maks(int n, ...){

    double num = 0,
           max = 0;

    va_list ap;
    va_start(ap,n);

    //Porównanie kolejnych argumento liczb
    for(int i = 0; i < n; i++){
        num = va_arg(ap, double);
        if(num > max)
            max = num;
    }

    va_end(ap);

    return max;

}

int main() {

    double result;

   result = maks(4.,5.,6.,3.,6.2);
   cout << result;
    return 0;
}