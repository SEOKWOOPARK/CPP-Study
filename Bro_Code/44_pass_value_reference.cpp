// 44. Pass by value - Pass by reference

#include <iostream>

using namespace std;

void swap_by_reference(string &a, string &b) {
    string temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_by_value(string a, string b) {
    string temp;
    temp = a;
    a = b;
    b = temp;
}


int main() {

    string m = "m";
    string n = "n";

    string j = "j";
    string k = "k";

    swap_by_reference(m, n);
    swap_by_value(j, k);

    std::cout << m << " " << n << std::endl;
    std::cout << j << " " << k << std::endl;

    return 0;
}



