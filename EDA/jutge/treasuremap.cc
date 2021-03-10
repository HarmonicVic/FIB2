#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<char>> &mat, int i, int j)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<pair<int, int>, int>> next;
    next.push(make_pair(make_pair(i, j), 0));

    int x, y, d;
    while (!next.empty())
    {
        x = (next.front().first).first;
        y = (next.front().first).second;
        d = next.front().second;
        next.pop();

        if (mat[x][y] == 't')
            return d;
        else if (!visited[x][y])
        {
            visited[x][y] = true;
            if (x != 0 and mat[x - 1][y] != 'X')
                next.push(make_pair(make_pair(x - 1, y), d + 1));
            if (x != n - 1 and mat[x + 1][y] != 'X')
                next.push(make_pair(make_pair(x + 1, y), d + 1));
            if (y != 0 and mat[x][y - 1] != 'X')
                next.push(make_pair(make_pair(x, y - 1), d + 1));
            if (y != m - 1 and mat[x][y + 1] != 'X')
                next.push(make_pair(make_pair(x, y + 1), d + 1));
        }
    }
    return -1;
}

int main()
{
    //creating map
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mat[i][j];
        }
    }
    int r, c;
    cin >> r >> c;
    int dist = bfs(mat, r - 1, c - 1);
    if (dist == -1) cout << "no treasure can be reached" << endl;
    else cout << "minimum distance: " << dist << endl;
}