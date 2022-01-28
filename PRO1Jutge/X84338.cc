#include <iostream>
using namespace std;

int main()
{
    string number;
    cin >> number;
    int leftSide = 0, rightSide = 0, aux;
    if (number.length() % 2 == 0)
    {
        for (int i = 0; i < number.length()/2; ++i)
        {
            leftSide += (int)number[i] - '0';
        }
        for (int i = number.length()/2; i < number.length(); ++i)
        {
            rightSide += (int)number[i] - '0';
        }
        if (leftSide < rightSide) cout << leftSide << " < " << rightSide << endl;
        else if (leftSide > rightSide) cout << leftSide << " > " << rightSide << endl;
        else cout << leftSide << " = " << rightSide << endl;
    }
    else cout << "nothing" << endl;
}