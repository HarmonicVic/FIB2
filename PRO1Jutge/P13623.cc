#include <iostream>
using namespace std;

int main()
{
    int r, c;
    string numberChunk;
    cin >> r >> c;
    int coins = 0;
    for (int i = 0; i < r; ++i)
    {
        cin >> numberChunk;
        for (int j = 0; j < c; ++j)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    coins += (int)numberChunk[j] - '0';
                    // cout << (int)numberChunk[j] - '0';
                }
            }
            else
            {
                if (j % 2 != 0)
                {
                    coins += (int)numberChunk[j] - '0';
                    // cout << (int)numberChunk[j] - '0';
                }
            }
        }
    }
    cout << coins << endl;
}