/***********************************************************************************************************
*7. Napisać funkcję ze zmienną liczbą argumentów,                                                          *
* która obliczy pole figury na podstawie podanych boków, zakładamy:                                        *
* 1 wartość kwadrat                                                                                        *
* 2 wartości prostokąt                                                                                     *
* 3 wartości trójkąt                                                                                       *
***********************************************************************************************************/


#include <iostream>
#include <cstdarg>
#include <cmath>

using namespace std;

void figuresCalc(int n, ...){

    double side1,side2,side3,result;

    va_list  ap;
    va_start(ap,n);

    switch (n){
        case 1: {
            side1 = va_arg(ap, double);
            result = (side1 * side1);   //Kwadrat a * a
            cout << " Pole: " << result << endl;
        }
            break;
        case 2: {
            side1 = va_arg(ap, double);
            side2 = va_arg(ap, double);
            result = (side1 * side2);       //Prostokat a * b
            cout << " Pole: " << result << endl;
        }
            break;
        case 3: {
            double p;   //Polowa obwodu trojkata
            side1 = va_arg(ap, double);
            side2 = va_arg(ap, double);
            side3 = va_arg(ap, double);
            p = (side1 + side2 + side3) / 2;        // p = (a*b*c)/2
            result = sqrt(((p - side1) * (p - side2) * (p - side3)) * p); //Pierwiastek z (p*(p-a)*(p-b)*(p-c))
            cout << " Pole: " << result << endl;
        }
            break;
        default:{
            cout << "Niepoprawny argument!" << endl;
        }
    }
        va_end(ap);
}

int main() {

    figuresCalc(3,2.,4.,5.);
    return 0;
}