#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

const int inf = numeric_limits<int>::max();

void print_path(const vector<int>& whereFrom, int start, int end){
    int i = whereFrom[end];
    if (start == end) {
        cout << end;
    }
    else {
        print_path(whereFrom,start,i);
        cout << ' ' << end;
    }
}

void bfs(vector<vector<int>>& adj, const int start, const int end){
    int n = adj.size();
    //queue<pair<int, int>> q;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<bool> vis(n, false);
    vector<int> dist(n,inf);
    vector<int> whereFrom(n,-1);
    q.push({start,0});

    while(!q.empty()){
        int nodo = q.top().first;
        int cost = q.top().second;
        if (nodo == end) {
            print_path(whereFrom, start, end);
            return;
        }
        q.pop();

        if (!vis[nodo]){
            vis[nodo] = true;
            for(auto it : adj[nodo]) {
                if (dist[it] > cost+1) {
                    q.push(make_pair(it, cost+1));
                    whereFrom[it] = nodo;
                    dist[it] = cost+1;
                }
            }
        }
    }
}

int main() {
    int n,m;
    while (cin >> n >> m){
        vector <vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        bfs(adj, 0,n-1);
        cout << endl;
    }
}