/************************************************************************************
* 4. Napisz funkcję, która po podaniu przez użytkownik imienia i nazwiska,          *
* jako jedna zmienna, zapisze osobno do 2 tablic imię i nazwisko                    *
************************************************************************************/


#include <iostream>

using namespace std;

void name_separate(char *name_tab, char *surname_tab){
    //Wskazniki na tablice w argumencie
    char *pname = name_tab,
         *psurname = surname_tab,
         *input_ptr = nullptr;

    //Pobranie danych od uzytkownika
    string name;
    cout << "Podaj swoje Imie i Nazwisko: ";
    getline(cin,name);

    char *pinput = new char[name.length() + 1];     //Tworzy robocza tablice char o dlugosci "name" +1
    input_ptr = pinput;                             //Wskaznik na wskaznik dynamicznego przydzialu pamieci-
                                                    //-oryginalny posluzy do usuniecia przydzielonej pamieci


    //Wpisywanie wartosci string do roboczej tablicy char
    int i = 0;
    for(i = 0; i < name.length(); i++){
        *(input_ptr + i) = name[i];
    }
    *(input_ptr + i) = '\0';                       //Dodanie znaku konca ciagu


    //Uzupelnianie pierwszej tablicy do znaku spacji badz konca tekstu
    while((*(input_ptr) != ' ') && (*(input_ptr) != '\0')){
        *pname++ = *input_ptr++;
    }
    *pname = '\0';                                 //Dodaje znak konca do pierwszej tablicy


    input_ptr++;                                   //Przesuniecia wskaznika tablicy roboczej +1 na poczatek kolego znaku


    //Uzupelnianie drugiej tablicy do znaku spacji badz konca tekstu
    while((*(input_ptr) != ' ') && (*(input_ptr) != '\0')) {
        *psurname++ = *input_ptr++;
    }
    *psurname = '\0';                              //Dodaje znak konca do drugiej tablicy

    pname = nullptr;
    psurname = nullptr;
    input_ptr = nullptr;
    delete[] pinput;
}

int main() {
 char tabname1[15],
      tabname2[15];

    name_separate(tabname1,tabname2);
    cout << tabname1 << " " << tabname2 <<endl;

    return 0;
}
