#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    string line, name;
    vector<queue<string>> qs(n+1);
    queue<string> sortides;
    for (int i = 0; i < n+1; ++i) {
        getline(cin,line);
        if (line.empty()){
            continue;
        }
        istringstream ss(line); // agafa una linea amb strings "acaba amb \n" i els separa en strings
        while (ss >> name){
            qs[i].push(name);
        }

    }
    
    string op;
    while (cin >> op) {
        int num;
        if (op == "SURT") {
            cin >> num;
            if (num >= 1 and num <= n) {
                if(!qs[num].empty()){
                    sortides.push(qs[num].front());
                    qs[num].pop();
                }
            }
        }
        else if (op == "ENTRA") {
            string name;
            cin >> name >> num;
            if (num >= 1 and num <= n) {
                qs[num].push(name);
            }
        }
    }
    cout << "SORTIDES" << endl;
    cout << "--------" << endl;
    while(!sortides.empty()){
        cout << sortides.front() << endl;
        sortides.pop();
    }
    cout << endl;
    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "cua " << i << ":";
        while (not qs[i].empty()) {
            cout << ' ' << qs[i].front();
            qs[i].pop();
        }
        cout << endl;
    }
}