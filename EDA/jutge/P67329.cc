#include <iostream>
#include <vector>

using namespace std;

char ADN[] = {'A', 'C', 'G', 'T'};

void print_dna(vector<char>& sol) {
    int n = sol.size();
    for (int i = 0; i < n; ++i) {
        cout << sol[i];
    }
    cout << endl;
}

void backtrack (vector<char>& sol, int& idx, const int& n) {
    if (idx == n) {
        print_dna(sol);
    }
    else {
        for (auto i : ADN) {
            sol.push_back(i);
            idx++;
            backtrack(sol, idx, n);
            idx--;
            sol.pop_back();
        }
    }
}

void backtrack(int& n) {
    vector<char> dna;
    int idx = 0;
    backtrack(dna, idx, n);
}

int main() {
    int n;
    cin >> n;
    backtrack(n);
}
