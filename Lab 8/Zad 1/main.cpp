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
void random_question();
void display(int);
void initiate(string);
void play();
char answer_check();


int questi_cout;    //Liczba wczytanych pytan
Question *questions_arr; //Wskażnik do tablicy wczytanych pytan
int *rand_arr; //Wskaznik do tablicy losowych niepowtarzajacych sie cyfr

int main() {
    initiate("plik.txt");
    play();

    return 0;
}

/*Tworzy tablice struktur o wielkosci podanej w argumencie i wczytuje do niej dane
Zapisuje liczbe wczytanych pytan do zmiennej globalnej na wypadek mniejszej ilosci
pytan niż zadeklarowano aby nie wyswietlac potem pustych wartosci
Zabezpieczone przed wykroczeniem poza tablice i mniejsza iloscia pytan w pliku
Argumenty: file Nazwa pliku
           total_questions ilosc pytan */
void questions_read(string file, int total_questions){

    questions_arr = new Question[total_questions]; //Tworzy tablice struktur
    Question *ptr = questions_arr; //Nowy wskaznik na początek tablicy

    fstream plik;
    plik.open(file, ios::in);

    string input;

    if (plik.fail()) {
        throw "Blad otwarcia pliku!\nSprawdz poprawnosc nazwy badz sciezki do pliku";
    } else {
        int i = 0;
        while (i < total_questions && !plik.eof()) {
            getline(plik, ptr[i].title);
            getline(plik, ptr[i].answer_A);
            getline(plik, ptr[i].answer_B);
            getline(plik, ptr[i].answer_C);
            getline(plik, ptr[i].answer_D);
            getline(plik, ptr[i].correct);
            i++;

        }
        questi_cout = i; //Zapisuje ilosc wczytanych pytan z pliku
    }

    plik.close();
    ptr = nullptr;
}

//Losuje nie powtarzajace sie liczby i umieszcza je w globalnej tablicy
// pod wskaznikiem *rand_arr
 void random_question() {
            int num, //Wylosowana liczba
            index = 0, //Indeks tablicy wylosowanych liczb
            sum = 0,    //Suma tablicy trafien

            tab[questi_cout];  //Tablica trafien
            rand_arr = new int[questi_cout]; //Tablica pytan w losowej kolejnosci

     for (int i = 0; i < questi_cout; tab[i] = 1, i++); //Tablica juz wylosowanych pytan (trafien) wypelniamy jedynkami

     do {
         //Zlicza sume z tablicy trafien
         sum = 0;
         for (int i = 0; i < questi_cout; i++) {
             sum += tab[i];
         }

         //Losuje liczbe
         srand(time(NULL));
         num = rand() % (questi_cout);

         if (tab[num]) { //Jezeli numer pytania jeszcze nie wypadl
             tab[num] = 0;   //Wpisuje 0 w tablice pytan (oznacza jako wylosowane)
             rand_arr[index] = num; //Zapisujemy wylosowana liczbe jako kolejna
             index++;   //Przesowamy index na nastepna pozycje
         }
     } while (sum);     //Dopoki tablica trafien nie wypelni sie zerami
}

void initiate(string plik ) {
    cout << "Wczytuje pytania...." << endl;
    try {
         questions_read(plik, 7);
         cout << "Losuje pytania...." << endl;
         random_question();
    }
    catch (const char *a) {
        cout << a << endl;
    }
}

void display(int i){
        cout << questions_arr[i].title << endl;
        cout << questions_arr[i].answer_A << endl;
        cout << questions_arr[i].answer_B << endl;
        cout << questions_arr[i].answer_C << endl;
        cout << questions_arr[i].answer_D << endl;
}

void play(){
    bool win = false;
    cout << "Witaj w grze!" << endl;
    cout << "Odpowiedz na wszystkie pytania i wygraj!\n" << endl;

    string answer;
    for(int i = 0; i < questi_cout; i++){
        int num = rand_arr[i];
        display(num); //Wyswietla pytania
        answer = answer_check(); //Zapisuje sprawdzona odpowiedz

        //Sprawdza poprawnosc odpowiedzi
        if(answer == questions_arr[num].correct){
            cout << "Poprawna odpowiedz\n" << endl;
            win = true;
        }
        else{
            cout << "Bledna odpowiedz!"<<endl;
            cout << "Poprawna odpowiedz to: " << questions_arr[num].correct << endl;
            cout << "Koniec gry" << endl;
            break;
        }
    }
    if(win)
        cout << "Gratulacje wygrales!!!";
}

char answer_check() {
    char input;
    bool correct_sign = false;

    do {
        cout << "Podaj swoja odpowiedz:";
        cin.get(input);
        cin.get();

        if (isalpha(input)) {
            input = tolower(input);
            if (input == 'a' || input == 'b' || input == 'c' || input == 'd') {
                correct_sign = true;
            } else
                cout << "Niepoprawne oznaczenie odpowiedzi. Poprawne to A, B, C lub D." << endl;
        } else if (isdigit(input)) {
                cout << "Odpowiedz nie moze byc liczba. Poprawne to A, B, C lub D." << endl;
        }
        }while (!correct_sign);

        return input;
}


