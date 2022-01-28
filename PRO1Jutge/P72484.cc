#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= (2 * n - 1); ++i)
    {
        if (i <= n)
        {
            for (int j = 0; j < n - i; ++j)
            {
                cout << ' ';
            }
            for (int j = n - i; j < n + i - 1; ++j)
            {
                cout << '*';
            }
        }
        else if (i > n)
        {
            for (int k = 0; k < i - n; ++k)
            {
                cout << ' ';
            }
            for (int k = i - n; k < (2 * n - 1) - (i - n); ++k)
            {
                cout << '*';
            }
        }
        cout << endl;
    }
}