#include <iostream>
#include <vector>
using namespace std;

bool resistant_search(double x, const vector<double> &v, int left, int right)
{
    if (left > right)
        return false;
    int mid = (left + right) / 2;
    if (x == v[mid + 1] or x == v[mid - 1] or x == v[mid])
        return true;
    if (x < v[mid])
        return resistant_search(x, v, left, mid);
    if (x > v[mid])
        return resistant_search(x, v, mid, right);
    return true;
}

bool resistant_search(double x, const vector<double> &v)
{
    return resistant_search(x, v, 0, v.size() - 1);
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<double> V(n);
        for (int i = 0; i < n; ++i)
            cin >> V[i];
        int t;
        cin >> t;
        while (t--)
        {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
