#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;
    int n, p;
    for (int i = 0; i < 3; ++i)
    {
        cin >> n >> p;
        m[n] = p;
    }
    auto it = m.begin();
    for (; it != m.end(); ++it)
    {
        cout << (*it).first << ' ' << (*it).second << endl;
    }
    cout << endl;

    it = m.end();
    it--;
    cout << (*it).first << endl;
}