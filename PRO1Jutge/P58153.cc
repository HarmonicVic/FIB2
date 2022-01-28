#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);
    double n, m;
    double totalN = 0, totalM = 0;
    while (cin >> n)
    {
        cin >> m;
        if (n != 0)
        {
            for (double i = 1; i <= n; ++i)
            {
                totalN += (1 / i);
                if (m != 0 && i <= m)
                    totalM += (1 / i);
            }
        }
        cout << totalN - totalM << endl;
        totalM = totalN = 0;
    }
}