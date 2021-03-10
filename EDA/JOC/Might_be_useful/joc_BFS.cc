#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//finds the nearest object searched for from an initial distance and returns the position at which the object is
//distance can be later calculated outside of the bfs algorithm to avoid useless operations
//invariant: we suppose i and j are valid positions in the map 
//returns position [1:n],[1:m]
pair<int, int> bfs(int i, int j)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<pair<pair<int, int>,bool>> visited;

    queue<pair<int, int>> next;
    next.push(make_pair(i, j));

    int x, y;
    while (!next.empty())
    {
        x = next.front().first;
        y = next.front().second;
        next.pop();

        if (mat[x][y] == 't')       //insert objective here 
            return {x,y};
        else if (!visited)
        {
            visited[x][y] = true;
            if (x != 0 and mat[x - 1][y] != 'X')        //'X' stands for wall / obstacle
                next.push(make_pair(x - 1, y));
            if (x != n - 1 and mat[x + 1][y] != 'X')
                next.push(make_pair(x + 1, y));
            if (y != 0 and mat[x][y - 1] != 'X')
                next.push(make_pair(x, y - 1));
            if (y != m - 1 and mat[x][y + 1] != 'X')
                next.push(make_pair(x, y + 1));
        }
    }
    //no such entity found
    return {-1,-1};
}

int main()
{
    //creating test map
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
    //starting point
    int r, c;
    cin >> r >> c;
    pair<int, int> dist = bfs(r - 1, c - 1);
    if (dist.first == -1 and dist.second == -1) cout << "no treasure can be reached" << endl;
    else cout << "position: " << dist.first << ' ' << dist.second << endl;
}