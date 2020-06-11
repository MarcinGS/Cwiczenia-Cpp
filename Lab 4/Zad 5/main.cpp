/********************************************************************************************
* 5. Napisz funkcję, która w każdej linii pliku tekstowego zastępuje wszystkie wystąpienia  *
* zadanego ciągu znaków innym ciągiem znaków.                                               *
* Nazwa pliku, słowo zastępowane oraz zastępujące powinny być kolejnymi parametrami funkcji.*
********************************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void word_replace(string target_file, string s_word, string r_word){

    string tekst;   //Zmienna na tekst
    int pos = 0;        //zmienna na pozycje szukanego wyrazu

    fstream infile(target_file, ios::in);   //Otwarcie pliku do odczytu

    //Jeśli otworzy wykonuje dzialania
    if(infile) {
       getline(infile,tekst,'\0');  //Pobiera tresc tekstu
        pos = tekst.find(s_word);               //Wyszukuje pozycje wystapienia szukanego wyrazu

        //Jeśli funkcja .find() znajdzie wyraz
        if(pos != string::npos) {
           tekst.erase(pos, s_word.size());   //Usowa szukany
           tekst.insert(pos, r_word);           //Wstawia nowy

           infile.close();         //Zamyka plik do odczytu

           fstream outfile(target_file,ios::out);      //Otwiera plik do zapisu
           outfile << tekst;                           //Zapis
           outfile.close();                            //Zamkniecie pliku do zapisu
        }
        else {
            cout << "Nie znaleziono" << endl;
        }
        infile.close();
    }
    else
        cout << "Blad otwarcia pliku!";
}

int main() {

    word_replace("plik.txt", "wyraz2", "przyklad");
    return 0;
}