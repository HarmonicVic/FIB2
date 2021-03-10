#include <iostream>
#include <vector>

using namespace std;

void permutacions(vector<int>& v, int& n)
{
    if (v.size() == n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << v[i];
            if (i != n - 1)
                cout << ' ';
        }
        cout << endl;
    }
    else
    {
        v[n] = 0;
        n++;
        permutacions(v, n);
        n--;

        v[n] = 1;
        n++;
        permutacions(v, n);
        n--;
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    n = 0;
    permutacions(v, n);
}