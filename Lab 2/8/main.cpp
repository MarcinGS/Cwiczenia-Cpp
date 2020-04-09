/*************************************************************************************************
 * Napisz funkcję char* strrchr(char *tekst, char *sub_tekst)                                    *
 * zwracającą wskaźnik na pierwsze wystąpienia łańcucha znaków sub_tekst w łańcuchu znaków tekst.*
 ************************************************************************************************/


#include <iostream>

using namespace std;

char *strrchr(char *tekst, char *sub_tekst){

    char *psub_tekst = sub_tekst; //Wskaznik na poczatek szukanego tekstu
    char *ptekst = tekst;         //Wskaznik na poczatek zrodlowego tekstu
    char *presult = nullptr;      //Wskaznik na wynik (pierwszego wystapienia)

    while(*psub_tekst != '\0'){         //Dopoki nie sprawdzisz wszystkich znakow
        if(*psub_tekst == *ptekst){     //Jeżeli znalazles pierwsze wystapienie szukanej litery
           if(presult == nullptr)       //i wczesniej nie znalazles pierwszego wystapienia
               presult = ptekst;        //ustaw wskaznik na pierwsze wystapienie znaku
            psub_tekst++;               //sprawdzaj dalej czy kolejne znaki sie zgadzaja
            ptekst++;
        }
        else{                     //Jeżeli szukany znak nie jest zgodny ze wzorem
            presult = nullptr;    //Zeruje wskaznik pierwszego wystapienia (bo tylko pare liter moglo być podobnych)
            ptekst++;             //przesowamy wskaznik na tekscie zrodlowym dalej bo wczesniejsze sa juz sprawdzone
            psub_tekst = sub_tekst;//Wskaznik szukanego tekstu na poczatek, sprawdzamy (porownujemy) od nowa
        }

        if((*ptekst == '\0') && (*psub_tekst != '\0')) {         //Wskaznik tekstu zrodlowego dotarl do konca a
            cout << "Szukanego ciagu nie ma w tekscie" << endl;  //szukanej frazy nie. W tekscie jest tylko fragment
            break;                                               //tekstu badz nie ma go wcale
        }
    }
    psub_tekst = nullptr;
    ptekst = nullptr;
    return presult;     //Zwraca wynik
}

int main() {

    char tab[] = {"marcin golis"};
    char tab1[] = {"golis"};
    char *ptr = strrchr(tab,tab1);
    cout << *ptr;
    ptr = nullptr;
    return 0;
}