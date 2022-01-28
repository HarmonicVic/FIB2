#include <iostream>
using namespace std;

int main()
{
    int n;
    //controls spacing
    bool ini = true;
    while(cin >> n)
    {
        if (!ini) cout << endl;
        ini = false;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << n;
            }
            cout << endl;
        }
    }
}