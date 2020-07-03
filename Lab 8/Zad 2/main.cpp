/*************************************************************************************************
 * 2. Napisz używając funkcji program do obsługi warsztatu samochodowego.                        *
 * Program ma mieć możliwość przyjęcia nowego samochodu do serwisu.                              *
 * Wyszukania w bazie (tablica lub plik) samochodu i dołożenie kolejnej naprawy.                 *
 * Wyświetlenie informacji o samochodzie i jego naprawach. Edycja danych właściciela i samochodu.*
 ************************************************************************************************/
#include <iostream>

using namespace std;
struct Repair{
    string  what,
            cost;
};
struct Client{
    string  name,
            surname,
            telephone;
};

struct Car {
    string  mark,
            model,
            reg_num;
    Client client;
    Repair repair;
};

Car add_car();
void search(const Car*);
void add_repair(Car*);
void show_info(const Car*,int);
void edit_info(Car*);

const int SIZE = 100;

int main() {
    Car car_tab[SIZE];
    char input;
    Car *car_ptr = car_tab;
do {
    cout << "\nProgram warsztatowy v 1.0" << endl;
    cout << "Wybierz odpowiednia opcje:" << endl;
    cout << "1. Dodaj auto.\n2. Wyszukaj w bazie.\n3. Dodaj naprawe." << endl;
    cout << "4. Wyswietl INFO.\n5. Edycja danych.\n0. Zakoncz program"<< endl;
    cout << "Wybor >>";
    cin >> input;

    switch (input) {
        case '1': {
            *car_ptr = add_car();
            car_ptr++;
        }
            break;
        case '2': {
            search(car_tab);
        }
            break;
        case '3': {
            add_repair(car_tab);
        }
            break;
        case '4': {
            int index;
            cout << "Podaj numer porzadkowy samochodu: ";
            cin >> index;
             show_info(car_tab,index);
        }
            break;
        case '5': {
            edit_info(car_tab);
        }
            break;
        case '0': {
            cout << "Koniec programu..." << endl;
        }
            break;
        default: {
            cout << " Niepoprawny wybor!" << endl;
        }
    }
}while (input != '0');

    car_ptr = nullptr;
    return 0;
}

Car add_car(){
    Car car;
    cout << "Marka samochodu: "<< endl;
    cin >> car.mark;
    cout << "Model samochodu: "<< endl;
    cin >> car.model;
    cout << "Numer rejestracyjny samochodu: "<< endl;
    cin >> car.reg_num;
    cout << "Imie klienta: "<< endl;
    cin >> car.client.name;
    cout << "Nazwisko klienta: "<< endl;
    cin >> car.client.surname;
    cout << "Telefon do klienta: "<< endl;
    cin >> car.client.telephone;
    cout << "Dane wprowadzone." << endl;
    return car;
}

void show_info(const Car *tab, int i){

    if (i > SIZE || i < 1)
        cout << "Niepoprawny indeks!" << endl;
    else{
        cout << "Nr: " << i << endl;
        i-=1; //Dla numeracji od 1
        cout << "Marka: " << tab[i].mark << "\nModel: " << tab[i].model;
        cout << "\nNumer rejestracyjny: " << tab[i].reg_num << "\nImie klienta: " << tab[i].client.name;
        cout << "\nNazwisko klienta: " << tab[i].client.surname << "\nTelefon klienta: " << tab[i].client.telephone;
        cout << "\nOpis naprawy: " << tab[i].repair.what << "\nKoszt naprawy: " << tab[i].repair.cost << endl;
    }
}

void search(const Car *tab) {
    string input;
    bool find = false;
    cout << "Wyszukiwarka\nPodaj dane do wyszukania: " << endl;
    cin >> input;

    int i = 0;
    while (i < SIZE) {
        if (tab[i].model == input || tab[i].mark == input || tab[i].reg_num == input) {
            show_info(tab, (i + 1));
            find = true;
        } else if (tab[i].client.name == input || tab[i].client.surname == input || tab[i].client.telephone == input) {
            show_info(tab, (i + 1));
            find = true;
        } else if (tab[i].repair.what == input || tab[i].repair.cost == input){
            show_info(tab, (i + 1));
            find = true;
        }
        i++;
    }
    if (!find)
        cout << "Nie znaleziono!\n";
}

void add_repair(Car *tab){
    int index;
    string text;
    cout << "Podaj nr pozycji w bazie:";
    cin >> index;
    index -= 1;

    cout << "Podaj informacje o naprawie." << endl;
    cout << ">>";
    cin.ignore();
    getline(cin,text);
    tab[index].repair.what = text;

    cout << "Podaj cene naprawy." << endl;
    cout << ">>";
    cin >> text;
    tab[index].repair.cost = text;
}

void edit_info(Car *tab){
    cout << "Edycja danych" << endl;
    int index,
        input;
    cout << "Podaj numer porzadkowy samochodu: ";
    cin >> index;
    index -= 1;

    cout << "Wybierz odpowiednia pozycje do zmiany:" << endl;
    cout << "1. Marka.\n2. Model.\n3. Numer rejestracyjny." << endl;
    cout << "4. Imie.\n5. Nazwisko.\n6. Nr. Telefonu"<< endl;
    cout << "7. Informacje o naprawie.\n8. Cena naprawy "<< endl;
    cout << "Wybor >>";
    cin >> input;

        switch (input) {
            case 1: {
                cout << "Marka samochodu: "<< endl;
                cin >> tab[index].mark;
            }
                break;
            case 2: {
                cout << "Model samochodu: "<< endl;
                cin >> tab[index].model;
            }
                break;
            case 3: {
                cout << "Numer rejestracyjny samochodu: "<< endl;
                cin >> tab[index].reg_num;
            }
                break;
            case 4: {
                cout << "Imie klienta: "<< endl;
                cin >> tab[index].client.name;
            }
                break;
            case 5: {
                cout << "Nazwisko klienta: "<< endl;
                cin >> tab[index].client.surname;
            }
                break;
            case 6: {
                cout << "Telefon do klienta: "<< endl;
                cin >> tab[index].client.telephone;
            }
                break;
            case 7: {
                cout << "Opis naprawy: " << endl;
                getline(cin,tab[index].repair.what);
            }
                break;
            case 8: {
                cout << "Koszt naprawy: " << endl;
                cin >> tab[index].repair.cost;
            }
                break;
            default: {
                cout << " Niepoprawny wybor!" << endl;
            }
        }
}