#include <iostream>
using namespace std;

int main()
{
    int n;
    int result = 1;
    while (cin >> n)
    {
        if (n <= 9)
            cout << "The product of the digits of " << n << " is " << n << '.' << endl;
        else
        {
            string aux = to_string(n);
            while (n > 9)
            {
                cout << "The product of the digits of " << n << " is ";
                for (int i = 0; i < aux.length(); ++i)
                {
                    result *= (int)aux[i] - '0';
                }
                cout << result << '.' << endl;
                aux = to_string(result);
                n = result;
                result = 1;
            }
        }
        cout << "----------" << endl;
    }
}