#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

typedef vector<bool> VB;
typedef vector<VB> VVB;

// pair<int, int>directions[] = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

bool safe_from_ghosts(const VVC& laberinto, const int& i,const int& j){
    int n = laberinto.size();
    int m = laberinto[0].size();

    if(i - 1 >= 0 and laberinto[i-1][j] == 'F') return false;                         //F arriba
    if(i + 1 < n and laberinto[i+1][j] == 'F') return false;                          //F abajo
    if(j - 1 >= 0 and laberinto[i][j-1] == 'F') return false;                         //F izquierda
    if(j + 1 < m and laberinto[i][j+1] == 'F') return false;                          //F a la derecha
    if(j - 1 >= 0 and i - 1 >= 0 and laberinto[i-1][j-1] == 'F') return false;        //F izquierda-arriba
    if(j - 1 >= 0 and i + 1 < n and laberinto[i+1][j-1] == 'F') return false;         //F izquierda-abajo
    if(j + 1 < m and i - 1 >= 0 and laberinto[i-1][j+1] == 'F') return false;         //F derecha-arriba
    if(j + 1 < m and i + 1 < n and laberinto[i+1][j+1] == 'F') return false;          //F derecha-abajo
    return true;
}

bool bfs (const VVC& laberinto, const pair<int,int>& ini) {
    int n = laberinto.size();
    int m = laberinto[0].size();
    VVB vis(n,VB(m,false));
    queue<pair<int,int>> q;
    q.push(ini);
    if(not safe_from_ghosts(laberinto,ini.first, ini.second)) return false;
    while (not q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (laberinto[i][j] == 'B') return true;
        if (not vis[i][j]) {
            vis[i][j] = true;
            if (i + 1 < n and laberinto[i+1][j] != 'X' and safe_from_ghosts(laberinto,i+1,j)) {
                q.push(make_pair(i+1, j));
            }
            if (i - 1 >= 0 and laberinto[i-1][j] != 'X' and safe_from_ghosts(laberinto,i-1,j)) {
                q.push(make_pair(i-1, j));
            }
            if (j + 1 < m and laberinto[i][j+1] != 'X' and safe_from_ghosts(laberinto,i,j+1)) {
                q.push(make_pair(i, j+1));
            }
            if (j - 1 >= 0 and laberinto[i][j-1] != 'X' and safe_from_ghosts(laberinto,i,j-1)) {
                q.push(make_pair(i, j-1));
            }
        }
    }
    return false;
}

int main() {
    int r,c;
    while (cin >> r >> c) {
        pair <int,int> ini;
        ini.first = 1;
        ini.second = 1;
        VVC laberinto(r, VC(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j){
                cin >> laberinto[i][j];
                if (laberinto[i][j] == 'P') {
                    ini.first = i;
                    ini.second = j;
                }
            }
        }
        if (bfs(laberinto, ini)) cout << "yes";
        else cout << "no";
        cout << endl;
    }
}
