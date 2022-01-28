#include <iostream>
using namespace std;

int main()
{
    int n;
    int iterations = 0;
    while (cin >> n)
    {
        while(n != 1)
        {
            //if n is an even number, divide by 2
            if (n % 2 == 0)
            {
                n /= 2;
                iterations++;
            }
            //if n is odd, multiply by 3 and add 1
            else
            {
                n *= 3;
                n++;
                iterations++;
            }
        }
        cout << iterations << endl;
        iterations = 0;
    }
}