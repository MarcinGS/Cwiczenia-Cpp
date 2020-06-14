/*********************************************************************************************************
 * 1. Napisz funkcję, która wczyta od użytkownika linijkę zawierającą ciąg znaków. Program               *
 * powinien następnie spróbować przekonwertować wprowadzony tekst na liczbę typu int.                    *
 * W trakcie konwersji program ma prawo zwrócić dwa wyjątki: Wprowadzony ciąg zawiera                    *
 * nieprawidłowe znaki oraz Wprowadzona liczba jest za duża. Na sam koniec program                       *
 * powinien wypisać skonwertowaną liczbę na ekran.                                                       *
 * Przykładowo dla 1234 program wypisze liczbę 1234. Z kolei dla 123o4 zostanie zwrócony błąd            *
 * jak również dla 123.4. Drugi wyjątek powinien się pojawić jeśli wpisana liczba nie mieści się w       *
 * zakresie typu int.                                                                                    *
 ********************************************************************************************************/


#include <iostream>

using namespace std;

int numConvert(const char* data) {
	int a = 0;
	for (int i = 0; data[i] !='\0'; i++) {
		if (a * 10 < 0)
			throw "Wprowadzona liczba jest za duza";
		if (data[i] >= '0' && data[i] <= '9')
			a = a * 10 + data[i] - '0';
		else
			throw "Wprowadzony ciag zawiera nieprawidlowe znaki";
	}
	return a;
}

int main() {
	char* data = new char[32];
	cin.getline(data, 32);
	try {
		cout << numConvert(data);
	}
	catch (const char* msg) {
		cout << msg;
	}
	cout << endl;
	return 0;
}