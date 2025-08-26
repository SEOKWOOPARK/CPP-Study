#include <iostream>
using namespace std;

int main() {

    string name = "Bro";
    string *pName = &name;

    int age = 10;
    int *pAge = &age;

    string pizzas[3] = {"pizza1", "pizza2", "pizza3"};
    string *pPizzas = pizzas;

    cout << "pAge is "<< pAge << endl;
    cout << "*pAge is "<< *pAge << endl;

    cout << "pName is "<< pName << endl;
    cout << "*pName is "<< *pName << endl;


    cout << "*pPizzas is "<< *pPizzas << endl;
    cout << "pPizzas is "<< pPizzas << endl;

    return 0;
}