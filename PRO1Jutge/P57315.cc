#include <iostream>
using namespace std;

int main()
{
    int i, j, k;
    cin >> i >> j >> k;
    string letters;
    cin >> letters;
    // controls the spacing
    bool ini = true;
    // find biggest, medium and smallest
    int smallest = min(min(i, j), k);
    int biggest = max(max(i, j), k);
    int medium = (i + j + k) - biggest - smallest;
    for (int a = 0; a < 3; ++a)
    {
        if (!ini)
            cout << ' ';
        ini = false;
        if (letters[a] == 'A')
        {
            cout << smallest;
        }
        else if (letters[a] == 'B')
        {
            cout << medium;
        }
        else
            cout << biggest;
    }
    cout << endl;
}