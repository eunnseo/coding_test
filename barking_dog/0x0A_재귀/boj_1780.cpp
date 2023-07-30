#include <iostream>
#include <cmath>
using namespace std;

int board[3000][3000];
int n_minus = 0;
int n_zero = 0;
int n_one = 0;

void recur(int k, int row, int col)
{
    // cout << "\tk = " << k << " / row = " << row << " / col = " << col << endl;
    int size = pow(3, k);
    int val = board[row][col];
    // cout << "\tsize = " << size << " / board[row][col] = " << val << endl;

    if (k == 0)
    {
        if (val == -1) n_minus++;
        else if (val == 0) n_zero++;
        else if (val == 1) n_one++;
        return;
    }

    bool is_same = true;
    for (int r = row; r < row+size; r++)
    {
        for (int c = col; c < col+size; c++)
        {
            if (val != board[r][c])
            {
                is_same = false;
                break;
            }
        }
    }
    if (is_same)
    {
        if (val == -1) n_minus++;
        else if (val == 0) n_zero++;
        else if (val == 1) n_one++;
        return;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                recur(k-1, row + (pow(3, k-1) * i), col + (pow(3, k-1) * j));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int k;
    for (k = 0; k <= 7; k++)
    {
        if (pow(3, k) == n) break;
    }
    recur(k, 0, 0);

    cout << n_minus << "\n"
         << n_zero << "\n"
         << n_one << "\n";

    return 0;
}