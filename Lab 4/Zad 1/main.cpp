/***********************************************************************************************************
* 1. Napisz funkcję, która wczytuje z klawiatury ciąg liczb całkowitych. Liczba zero kończy wczytywanie.   *
* Wczytane liczby zapisz do pliku tekstowego liczby.txt. Liczby oddziel znakiem spacji.                    *
***********************************************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int num;
    ofstream file("liczby.txt", ios::out);  //Otwarcie pliku do zapisu

    //Dopoki nie ma 0
    do {
        cout << "Podaj liczbe calkowita: ";
        cin >> num;
        file << num << " "; //Zapis w pliku
    }
    while(num != 0);

    file.close();       //Zamkniecie pliku

    return 0;
}