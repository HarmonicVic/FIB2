#include <iostream>
using namespace std;

int main()
{
    int n;
    int p = 0, q = 0;
    while (cin >> n)
    {
        while (n > 0)
        {
            if (n % 7 == 0)
            {
                n -= 7;
                p++;
            }
            else if (n % 4 == 0)
            {
                n -= 4;
                q++;
            }
            else
            {
                n -= 7;
                p++;
            }
        }
        cout << p << ' ' << q << endl;
        p = q = 0;
    }
}