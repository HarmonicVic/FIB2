#include <iostream>
#include <vector>

using namespace std;

vector<int> bazookas(10);
vector<int> money(10);

vector<int>::iterator itb;
vector<int>::iterator itm;

void read_grid(vector<vector<int>> &v)
{
    itb = bazookas.begin();
    itm = money.begin();
    for (int i = 0; i < v.size(); ++i)
        for (int j = 0; j < v[0].size(); ++j)
        {
            if (v[i][j] == 3)
            {
                *itb = i + j;
                ++itb;
            }
            else if (v[i][j] == 5)
            {
                *itm = i + j;
                ++itm;
            }
        }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];

    read_grid(v);
    auto itb2 = bazookas.begin();
    while (itb2 != itb) 
    {
        cout << *itb2 << ' ';
        itb2++;
    }
}