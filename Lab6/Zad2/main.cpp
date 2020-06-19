/*********************************************************************************************
 * 2. Zmodyfikuj szablon z zadania 1, tak aby przyjmował tablice o różnej liczbie elementów. *
 ********************************************************************************************/

#include <iostream>

using namespace std;

template <class T1, class T2>
T1 max5(T1 tab[], T2 n){
    T1 max = tab[0];
    for(int i = 1; i < n; i++){
        if(tab[i] > max)
            max = tab[i];
    }
    return max;
}

int main() {

    int tab[] = {1,3,5,7,6,8};
    int max = max5(tab,6);
    cout << max;

    return 0;
}

