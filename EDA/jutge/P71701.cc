#include <iostream> 
#include <vector>

using namespace std;

typedef vector <bool> VI;
typedef vector <VI> VVB;

// Imprimeix el tauler per terminal
void escriu_tauler (const VVB& tauler, const int& n) {
        for (int i = 0; i < n; ++i) {
            for (int j =0; j < n; ++j) {
                if (tauler[i][j]) cout << "K";
                else cout << '.' ;
            }
            cout << endl;
        }
        cout << "----------" << endl;
}

// No hi ha cap rei a les celes adjacents
bool colocar_rei(VVB& tauler, const int& n, const int& i, const int& j) {
    if (tauler[i][j]) return false;
    else if (i+1 < n and tauler[i+1][j]) return false; // abaix
    else if (i-1 >= 0 and tauler[i-1][j]) return false; // adalt
    else if (j+1 < n and tauler[i][j+1]) return false; // dreta 
    else if (j-1 >= 0 and tauler[i][j-1]) return false; // esquerra
    else if (i-1 >= 0 and j-1 >= 0 and  tauler[i-1][j-1]) return false;  // adalt esquerra
    else if (i-1 >= 0 and j+1 < n and tauler[i-1][j+1]) return false;   // adalt dreta
    else if (i+1 < n and j-1 >= 0 and tauler[i+1][j-1]) return false;   // abaix esquerra
    else if (i+1 < n and j+1 < n and tauler[i+1][j+1]) return false;   // abaix dreta
    else return true;
}

void reis(VVB& tauler, int x, int y, const int& r, int k) {
    int n = tauler.size();
    if (r == k) {
        escriu_tauler(tauler, n);
    }
    else { 
        bool primer = true;
        for (int i = x; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (primer) {
                    primer = false;
                    j = y;
                }
                if (colocar_rei(tauler, n, i, j)) {
                    tauler[i][j] = true; // colocar rei
                    reis(tauler, i, j, r, k+1); // universo donde colocamos el rei
                    tauler[i][j] = false; // universo en el que no colocamos el rei
                }
            }
        }
    }
}

// Preparem el backtracking
void reis (int n, int  r) { 
    VVB  tauler(n,VI(n,false) ) ;
    int row = 0;
    int x = 0;
    int y = 0;
    int k = 0;
    reis(tauler,x, y, r, k);
}

int main() {
    int n, r;
    cin >> n >> r;
    reis(n,r);
}
