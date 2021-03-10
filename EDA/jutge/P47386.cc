#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print_lios(map<string, string> lios){
    cout << "PARELLES:" << endl;
    for (auto it = lios.begin(); it != lios.end(); ++it){
        if (it->second != "" and it->first<it->second)
            cout << it->first << ' ' << it->second << endl;
        
    }
    cout << "SOLS:" << endl;
    for (auto it = lios.begin(); it != lios.end(); ++it){
        if(it->second == "")
            cout << it->first << endl;
    }
    cout << "----------" << endl;
}

int main() {
    string option, names;
    map<string, string> lios;
    while (cin >> option) {
        if (option == "liats") {
            string x,y;
            cin >> x >> y;
            if (lios[x] != "") lios[lios[x]] = "";
            if (lios[y] != "") lios[lios[y]] = "";
            lios[x] = y;
            lios[y] = x;
        }
        else if (option == "info") {
            print_lios(lios);
        }
    }
}
