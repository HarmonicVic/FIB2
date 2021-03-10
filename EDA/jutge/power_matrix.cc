#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multi2x2(const vector<vector<int>>& A, const vector<vector<int>>& B, int m){
    return {{A[0][0]*B[0][0] + A[0][1]*B[1][0] % m},{A[0][0]*B[0][1] + A[0][1]*B[1][1] % m},
            {A[1][0]*B[0][0] + A[1][1]*B[1][0] % m},{A[1][0]*B[0][1] + A[1][1]*B[1][1] % m}};
}

vector<vector<int>> exponent(const vector<vector<int>>& M, int n, int m){
    if (n == 0) return {{1,0},{0,1}};
    else if (n%2 == 0){
        vector<vector<int>> Y = exponent(M, n/2, m);
        return multi2x2(Y, Y, m);
    }
    else {
        vector<vector<int>> Y = exponent(M, n/2, m);
        return multi2x2(multi2x2(Y, Y, m), M, m);
    }
}

int main(){
    int m00, m01, m10, m11;    
    while (cin >> m00 >> m01 >> m10 >> m11){
        vector<vector<int>> M = {{m00,m01}, {m10,m11}};
        int n, m;
        cin >> n >> m;
        vector<vector<int>> R = exponent(M, n,m);
        cout << R[0][0] << ' ' << R[0][1] << endl;
        cout << R[1][0] << ' ' << R[1][1] << endl;
        cout << string(10, '-') << endl;
    }
}