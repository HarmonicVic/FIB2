#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);
    double x;
    cin >> x;
    double sequence;
    cin >> sequence;
    double solution = sequence;
    int exponent = 1;
    while (cin >> sequence)
    {
        solution += sequence * pow(x, exponent);
        exponent++;
    }
    cout << solution << endl;
}