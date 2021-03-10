#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

const int inf = numeric_limits<int>::max();

struct ciutat {
    int nit; // cost afegit de passar la nit en una ciutat
    int dist = inf; // distancia desde ciutat inicial fins a aquesta ciutat
};

typedef vector<ciutat> VC;
typedef vector<VC> VVC;

typedef vector<int> VI;
typedef vector<VI> VVI;

int dijkstra(const vector<vector<pair<int,int>>>& adj, VC ciutats, int inici, const int fin){
    // adj.first = coste
    // adj.second = vertice al que vamos
        
    if (inici == fin) return 0;
    priority_queue<pair <int,int >, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> vis(ciutats.size(), false);
    pq.push({0, inici});
    while (not pq.empty()) {
        int i = pq.top().second;
        if (i == fin) {
            return ciutats[i].dist;
        }
        int cost = pq.top().first;
        pq.pop();
        if (not vis[i]) {
            vis[i] = true;
            
            for (auto it : adj[i]) { //adj[i][j] = cost
                int td = it.first + cost;
                if (it.second != fin) td += ciutats[it.second].nit;
                if (ciutats[it.second].dist > td) {
                    ciutats[it.second].dist = td;
                    pq.push({td,it.second});
                }
            }
        }
    }
    return inf;
}

int main() {
    int n, m;
    cin >> n >> m;      //n son num de vertex, m son num d'arestes
    vector <vector<pair<int,int>>> adj(n); // adj[i] 'i' = se corresponde al vertice del que salimos  
    //vector <vector = nos guarda todas las adjacencias del nodo 'i'
    
    // adj[j] = 'j' no tiene sentido particular en cambio pair<int = coste,int = vertice al que vamos>
    // j es el orden en que hemos añadido esa adjacencia en particular
    VC ciutats(n);
    int aux;
    for (int i = 0; i < n; ++i){
        cin >> aux;
        ciutats[i].nit = aux;
    } 
    for (int i = 0; i < m; ++i) {
        int u,v,cost;
        cin >> u >> v >> cost;
        adj[u].push_back({cost,v});
        adj[v].push_back({cost,u});
    }
    int inici, fin;
    while (cin >> inici >> fin){
        cout << "c(" << inici << ',' << fin << ") = ";
        int dist = dijkstra(adj,ciutats, inici, fin);
        if (dist == inf) cout << "+oo";
        else cout << dist;
        cout << endl;
    }
}