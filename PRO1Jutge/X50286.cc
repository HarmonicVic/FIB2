#include <iostream>
using namespace std;

int main()
{
    string word;
    int counter = 0;
    while(cin >> word)
    {
        if (word == "hello") counter++;
    }
    cout << counter << endl;
}