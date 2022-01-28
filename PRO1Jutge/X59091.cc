#include <iostream>
using namespace std;

int main()
{
    int n, m;
    bool ini = true;
    int counter = 9;
    while (cin >> n)
    {
        cin >> m;
        if (!ini) cout << endl;
        ini = false;
        for (int i = 1; i <= n*m; ++i)
        {
            cout << counter;
            if(i % m == 0) cout << endl;
            if (counter > 0) counter--;
            else counter = 9;
        }
        counter = 9;
    }
}