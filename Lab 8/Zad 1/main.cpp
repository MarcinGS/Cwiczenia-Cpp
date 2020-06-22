 /*****************************************************************************************************
 * Napisz program realizujący grę Milionerzy. Program powinien być w całości napisany na funkcjach:   *
 * a. Funkcja odczytująca pytania z pliku                                                             *
 * b. Funkcja losująca pytania                                                                        *
 * c. Funkcje realizujące koła ratunkowe                                                              *
 * d. Funkcja odpowiadająca za stan gry                                                               *
 * e. ….                                                                                              *
 *****************************************************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

 struct Question{
     string title = "",
            answer_A = "",
            answer_B = "",
            answer_C = "",
            answer_D = "",
            correct = "";
 };

void questions_read(string, int);
int random_question(int, int[]);
void hint();
void play(string);


int points = 0,     //Suma punktow
    questi_cout = 5;    //Liczba wczytanych pytan
Question *questions_arr; //Wskażnik do tablicy wczytanych pytan

int main() {
    play("plik.txt");
    return 0;
}

//Tworzy tablice struktur o wielkosci podanej w argumencie i wczytuje do niej dane
//Zapisuje liczbe wczytanych pytan do zmiennej globalnej na wypadek mniejszej ilosci
//pytan niż zadeklarowano aby nie wyswietlac potem pustych wartosci
//Zabezpieczone przed wykroczeniem poza tablice i mniejsza iloscia pytan w pliku
//Argumenty: file Nazwa pliku
//           total_questions ilosc pytan
void questions_read(string file, int total_questions){

    questions_arr = new Question[total_questions]; //Tworzy tablice struktur
    Question *ptr = questions_arr; //Nowy wskaznik na początek tablicy

    fstream plik;
    plik.open(file, ios::in);

    string input;

    if(plik.fail()){
        throw "Blad otwarcia pliku!\nSprawdz poprawnosc nazwy badz sciezki do pliku";
    }
    else{
        int i = 0;
        while(i < total_questions || !plik.eof()){
            getline(plik,ptr[i].title);
            getline(plik,ptr[i].answer_A);
            getline(plik,ptr[i].answer_B);
            getline(plik,ptr[i].answer_C);
            getline(plik,ptr[i].answer_D);
            getline(plik,ptr[i].correct);
            i++;
        }
        questi_cout = i; //Zapisuje ilosc wczytanych pytan z pliku
    }
    plik.close();
    ptr = nullptr;
}

 int random_question( int *tab){
    int num,
        sum = 0;

    srand(time(NULL));
    num = rand()%(questi_cout-1);

     while(sum < questi_cout) //Tak dlugo az wylosuje wszystkie pytania {
        //Liczy ile i ktore pytania juz padly
        for(int i = 0; i < questi_cout; i++){
            sum += tab[i];
        }
        //Jezeli wylosowane pytanie juz bylo to losuje ponownie
        while (tab[num]) {
            num = rand() % (questi_cout - 1);
        }
        return num;
    }


void play(string plik ){

    int random_num;
    try{
       // questions_read(plik, num);
    }
    catch (const char* a) {
        cout << a << endl;
    }

    int tab[questi_cout];
    for(int i = 0; i < questi_cout; tab[i] = 0,i++); //Tablica juz wylosowanych pytan wypelniona zerami

    for(int i = 0; i < questi_cout; i++) {
        cout << "i= " << i << endl;
        random_num = random_question(tab);
        cout << random_num << endl;
        for (int j = 0; j < questi_cout; j++) {
            cout << tab[j];
        }
        cout << endl;
    }
}

//Cosik zle losuje