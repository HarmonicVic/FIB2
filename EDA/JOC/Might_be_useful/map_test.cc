#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main()
{
    int n;
    char v;
    map<int, stack<char>> m;
    for (int i = 0; i < 5; ++i)
    {
        cin >> n;
        for (int j = 0; j < 3; ++j)
        {
            cin >> v;
            m[n].push(v);
        }
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << ' ';
        while (!i->second.empty())
        {
            cout << i->second.top() << ' ';
            i->second.pop();
        }
        cout << endl;
    }
}