/**************************************************************************************************
*7. Napisz funkcję wczytującą plik tekstowy, następnie funkcja rozbija go na poszczególne litery  *
*i przedstawia analizę częstości występowania liter występujących w pliku.                        *
*Funkcja zwraca tablicę z częstością występowania poszczególnych liter.                           *
**************************************************************************************************/


#include <iostream>
#include <fstream>

using namespace std;

void letters_count(string plik){

    char ch;
    int result_tab[26][2];  //Tablica wynikow


    //Inicjalizacja tablicy wynikow kodami liter
    for(int i = 0,poz = 97; i < 26; i++,poz++){
        result_tab[i][0] = poz;
        result_tab[i][1] = 0;
    }

    fstream file(plik, ios::in);    //Otwarcie pliku do odczytu

    if(file){
        //Jezeli duza litera zmienia na mala
        while(file.get(ch)){
            if(ch > 64 && ch < 91)
                ch += 32;

            //Zlicza wystepowanie liter
            for(int i = 0; i < 26; i++){
                if(ch == result_tab[i][0])
                    result_tab[i][1]++;
            }
        }

        //Wyswietla wynik ilosci liter ktore wystapily w pliku
        for(int i = 0; i < 26; i++){
            ch = result_tab[i][0];
            if(result_tab[i][1] > 0)
                cout << "Litera: "  << ch << " wystapila " << result_tab[i][1] << " razy." << endl;
        }
    }
    else
        cout << "Blad otwarcia pliku";

    file.close();
}

int main() {

    letters_count("plik.txt");
    return 0;
}
