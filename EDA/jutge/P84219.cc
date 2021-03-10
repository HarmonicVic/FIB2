#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double> &v, int left, int right)
{
    if (left > right) return -1;
    int mid = (left + right)/2;
    if (x == v[mid])
    {
        if (v[mid -1] != x) return mid;
        else return first_occurrence(x, v, left, mid-1);
    }
    if (x < v[mid]) return first_occurrence(x, v, left, mid-1);
    if (x > v[mid]) return first_occurrence(x, v, mid+1, right);
    return mid;
}

int first_occurrence(double x, const vector<double> &v)
{
    int left = 0;
    int right = v.size() - 1;
    return first_occurrence(x, v, left, right);
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
            cout << first_occurrence(x, V) << endl;
        }
    }
}
