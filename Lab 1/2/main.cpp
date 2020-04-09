/*Napisz program wykorzystujący następujące funkcje:
a. Funkcja fill_array() jako parametr pobiera nazwę tablicy oraz jej wielkość.
   Użytkownik jest proszony o podanie wartości double, które zostaną wpisane do tablicy.
   Pobieranie danych jest przerywane, kiedy tablica jest pełna. Funkcja zwraca liczbę wprowadzonych wartości.
b. Funkcja show_array() jako parametr pobiera nazwę tablicy liczb double oraz wielkość tablicy po czym pokazuje zawartość tablicy
c. Funkcja reverse_array() jako parametr pobiera nazwę tablicy oraz jej wielkość, po czym odwraca kolejność liczb w przekazanej tablicy
 Program ma użyć opisanych funkcji do wypełnienia tablicy, wyświetlenia jej, odwrócenia i ponownego wyświetlenia*/



#include <iostream>

int fill_array(double tab[], int n);
void show_array(double tab[], int n);
void reverse_array(double tab[], int n);


using namespace std;

int main() {

      double tablica[5];

      cout << "Podaj 5 wartosci dla tablicy: " << endl;
      fill_array(tablica,5);

      cout << "Podane wartosci to: " << endl;
      show_array(tablica,5);

      reverse_array(tablica,5);

      cout << "Po odwruceniu wartosci tablica ma postac: " << endl;
      show_array(tablica,5);

    return 0;
}

int fill_array(double tab[], int n){
    //Uzupelnianie tablicy.
    for(int i = 0; i < n; i++ ){
        cout << "Podaj " << (i+1) << " wartosc double tablicy: " << endl;
        cin >> tab[i];
    }

    return n; //Liczba wprowadzonych wartości jest wielkoscia tablicy.
}


void show_array(double tab[], int n){
    //Wyświetla zawartość tablicy.
    for(int i = 0; i < n; i++){
        cout << tab[i] << ",";
    }
    cout << endl;
}

void reverse_array(double tab[], int n) {

    double rev_tab[n]; //Tablica z odwrocona kolejnoscia wartosci
    double *ptab = tab;  //Wskaznik ustawiony na podana tablice

    //Kopiowanie tablicy w odwrotnej kolejnosci
    for(int i = 0, j=(n-1); i < n; i++,j--){
        rev_tab[j] = tab[i];
    }

    //kopiowanie odwroconej tablicy do oryginalnej
    for(int i = 0; i < n; i++){
        ptab[i] = rev_tab[i];
    }
}