#include <iostream>
using namespace std;

int main()
{
    char input;
    cin >> input;
    if ((input <= 'z'&& input >= 'a') || (input >= 'A' && input <= 'Z')) cout << "lletra" << endl;
    else if (input >= '0' && input <= '9') cout << "digit" << endl;
    else cout << "res" << endl;
}