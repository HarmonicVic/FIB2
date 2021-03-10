#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI table(9, VI(9));

void escriu_sudoku(int n)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << table[i][j];
            if (j != 9 - 1)
                cout << ' ';
        }
        cout << endl;
    }
}
// Donada una posicio x,y del tauler de sudoku i un digit del 1-9
// la funcio ens retorna true si i nomes si podem posar el digit en aquella posicio
bool num_ok(int x, int y, int num)
{
    int start_row = x - x % 3; //calcula el box corresponent
    int start_col = y - y % 3;

    for (int j = 0; j < 9; ++j)
    { //mira la fila concreta
        if (table[x][j] == num)
            return false;
    }

    for (int i = 0; i < 9; ++i)
    { //mira la col concreta
        if (table[i][y] == num)
            return false;
    }

    for (int i = 0; i < 3; ++i)
    { //mira el box corresponent
        for (int j = 0; j < 3; ++j)
        {
            if (table[i + start_row][j + start_col] == num)
                return false;
        }
    }

    return true;
}

bool is_full()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (table[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool find_empty(int &row, int &col)
{
    for (row = 0; row < 9; ++row)
    {
        for (col = 0; col < 9; ++col)
        {
            if (table[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool sudoku()
{
    int i, j;
    if (!find_empty(i, j))
        return true;
    for (int k = 1; k <= 9; ++k)
    {
        if (num_ok(i, j, k))
        { // utilitzem 0 per dir que no hi ha numero definit
            table[i][j] = k;
            if (sudoku())
                return true;
            table[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << n << endl;
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char c;
                cin >> c;
                if (c == '.')
                    table[i][j] = 0;
                else
                    table[i][j] = c - '0';
            }
        }
        if (sudoku())
        {
            cout << endl;
            escriu_sudoku(n);
        }
    }
}