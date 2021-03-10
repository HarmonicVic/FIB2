#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

typedef vector<bool> VB;
typedef vector<VB> VVB;

void print_path(VC& path){
    for (int i = 0; i < path.size(); ++i){
        cout << path[i];
    }
    cout << endl;
}

//recursive
void pathing (VC path, VVB& vis, const VVC& maze, pair<int, int>& current, const pair<int, int> fi) {
    int n = maze.size();
    int m = maze[0].size();
    if(current.first == fi.first and current.second == fi.second) print_path(path);
    else {
        int i = current.first;
        int j = current.second;
        if (i+1 < n and not vis[i+1][j]){
            vis[i+1][j] = true;
            path.push_back(maze[i+1][j]);
            current = make_pair(i+1, j);
            pathing(path, vis, maze, current, fi);
            vis[i+1][j] = false;
            current = make_pair(i, j);
            path.pop_back();
        }
        if (i-1 >= 0 and not vis[i-1][j]){
            vis[i-1][j] = true;
            current = make_pair(i-1, j);
            path.push_back(maze[i-1][j]);
            pathing(path, vis, maze, current, fi);
            current = make_pair(i, j);
            path.pop_back();
            vis[i-1][j] = false;
        }
        if (j+1 < m and not vis[i][j+1]){
            vis[i][j+1] = true;
            current = make_pair(i, j+1);
            path.push_back(maze[i][j+1]);
            pathing(path, vis, maze, current, fi);
            current = make_pair(i, j);
            path.pop_back();
            vis[i][j+1] = false;
        }
        if (j-1 >= 0 and not vis[i][j-1]){
            vis[i][j-1] = true;
            path.push_back(maze[i][j-1]);
            current = make_pair(i, j-1);
            pathing(path, vis, maze, current, fi);
            vis[i][j-1] = false;
            current = make_pair(i, j);
            path.pop_back();
        }
    }   
}

//prepares
void pathing(VVC& maze, const pair<int,int>& inici, const pair<int,int>& fi){
    VC path;
    int n = maze.size();
    int m = maze[0].size();
    VVB vis(n, VB(m,false));
    pair<int,int> current;
    current.first = inici.first;
    current.second = inici.second;
    vis[current.first][current.second] = true;
    path.push_back(maze[inici.first][inici.second]);
    pathing(path, vis, maze, current, fi);
}

int main(){
    int n,m;
    cin >> n >> m;
    VVC maze(n,VC(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    pair<int, int> inici, fi;
    cin >> inici.first >> inici.second;
    cin >> fi.first >> fi.second;

    pathing(maze, inici, fi);
}
