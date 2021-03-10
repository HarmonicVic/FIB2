#include <iostream>
#include <vector>

using namespace std;

int first_occurrence(double x, const vector<double>& v);
int first_occurrences(double x, const vector<double>& v, int l, int r);

int main(){
    int n;
    cin >> n;
    vector<double>v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int searched;
    cin >> searched;
    cout << first_occurrence(searched, v) << endl;
}

int first_occurrence(double x, const vector<double>& v){
    return first_occurrences(x, v, 0, v.size()-1);
}

int first_occurrences(double x, const vector<double>& v, int l, int r){
    if (l > r) return -1;
    else{
        int m = (l+r)/2;
        if (v[m] == x) {
            if (m-1 < l or v[m-1] != x) return m;
            else return first_occurrences(x, v, l, m-1);
        }
        else if (v[m] < x) return first_occurrences(x, v, m+1, r);
        else if (v[m] > x) return first_occurrences(x, v, l, m-1);
    }
}