#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

void word_replace(string target_file, string s_word, string r_word){

    /* String porownywaz zapamietywac pierwsza pozycje lini pos i zapisywac*/
    const int MAX_SIZE = 100;
    string zdanie;
    char tab[MAX_SIZE];
    long int pos = 0;

    fstream file;
    file.open(target_file, ios::in|ios::out);

    if(file){
        while(getline(file, zdanie)){
            cout << zdanie << endl;
            int i = 0;
            int j = 0;
            while(zdanie[i]){
                if(zdanie[i] == s_word[j]) {
                    i++;
                    j++;
                }

            }



        }
        file.close();
    }
    else
        cout << "Blad otwarcia pliku!";
}


int main() {

    word_replace("plik.txt", "wyraz2", "przyklad");
    return 0;
}