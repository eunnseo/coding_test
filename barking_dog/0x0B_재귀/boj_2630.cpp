#include <iostream>
using namespace std;

int n;
int board[130][130];
int color[2]; // 0: white, 1: blue

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
}

void recur(int row, int col, int size)
{
    if (size == 1)
    {
        color[board[row][col]]++;
        return;
    }

    bool is_same_color = true;
    int c = board[row][col];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[row+i][col+j] != c)
            {
                is_same_color = false;
                break;
            }
        }
    }

    if (is_same_color)
    {
        color[c]++;
        return;
    }

    size >>= 1;
    recur(row, col, size);
    recur(row+size, col, size);
    recur(row, col+size, size);
    recur(row+size, col+size, size);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    recur(0, 0, n);

    cout << color[0] << "\n" << color[1];

    return 0;
}