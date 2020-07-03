#include <iostream>
using namespace std;

void f(int &x) { ++x; }

int a = 0;


int main() {

    f(a);
    cout << a;
    return 0;
}