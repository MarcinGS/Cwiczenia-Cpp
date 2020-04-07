/********************************************************************************************************************
 * Zadanie 1                                                                                                          *
 * Napisz funkcję usuwająca z podanego ciągu znaków wszystkie powtarzające się spacje.                                *
 ********************************************************************************************************************/
#include <iostream>

using namespace std;

void space_remover(char *text){

    int i = 0;
    while(*(text+i) != '\0'){                     //Dopoki nie napotkasz znaku konca ciagu
        if(*(text+i) && *(text + (i+1)) == ' ') { //Jeśli napotkasz powtarzajace sie spacje
            int j = (i+1);                        //To od miejsca drugiej spacji
            while (*(text+j) != '\0') {           //poki nie dojdziesz do konca
                *(text+j) = *(text + (j+1));      //nadpiszesz wskazany znak kolejnym(przesuniesz reszte textu w lewo)
                j++;
            }
            *(text+j) = '\0';                     //Dodawanie znaku końca ciagu
        }
        i++;
    }
    *(text+i) = '\0';                             //Dodawanie znaku końca ciagu

}
int main() {

    char text_tab[10] = {"  12  567"};

    //Wyswietlenie tablicy oryginalnej
    for(char i: text_tab){
        cout << i;
    }

    space_remover(text_tab);

    //Wyswietlenie tablicy po wykonaniu funkcji
    cout << "\n";

    for(char i: text_tab){
        cout << i;
    }

    return 0;
}

