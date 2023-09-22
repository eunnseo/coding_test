#include <iostream>
using namespace std;

int n;
string board[66];
string res;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
}

void recur(int row, int col, int size, int idx)
{
    if (idx == 0) res.push_back('(');
    
    char pixel = board[row][col];
    bool is_same = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (pixel != board[row+i][col+j])
            {
                is_same = false;
                break;
            }
        }
    }

    if (is_same)
    {
        res.push_back(pixel);
    }
    else
    {
        size >>= 1;
        recur(row, col, size, 0);
        recur(row, col+size, size, 1);
        recur(row+size, col, size, 2);
        recur(row+size, col+size, size, 3);
    }

    if (idx == 3) res.push_back(')');
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    recur(0, 0, n, -1);
    cout << res;

    return 0;
}