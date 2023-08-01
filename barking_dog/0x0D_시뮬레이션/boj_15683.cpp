#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

int row, col;
int board[10][10];
vector<pair<int, int>> cctv;
int min_zero = 64;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int countZero()
{
    int res = 0;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (board[r][c] == 0) res++;
        }
    }
    return res;
}

void check(pair<int, int> loc, int dir)
{
    dir %= 4;
    while (1)
    {
        int nx = loc.X + dx[dir];
        int ny = loc.Y + dy[dir];
        loc = {nx, ny};
        
        if (nx < 0 || ny < 0 || nx >= row || ny >= col) return;
        if (board[nx][ny] == 6) return;
        if (board[nx][ny] != 0) continue;

        board[nx][ny] = -1;
    }
}

void solve(int idx)
{
    if (idx == cctv.size())
    {
        int n_zero = countZero();
        if (n_zero < min_zero) min_zero = n_zero;
        return;
    }

    int x = cctv[idx].X;
    int y = cctv[idx].Y;

    int backup[10][10];

    for (int dir = 0; dir < 4; dir++)
    {
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                backup[r][c] = board[r][c];

        if (board[x][y] == 1)
        {
            check({x, y}, dir);
        }
        else if (board[x][y] == 2)
        {
            check({x, y}, dir);
            check({x, y}, dir + 2);
        }
        else if (board[x][y] == 3)
        {
            check({x, y}, dir);
            check({x, y}, dir + 1);
        }
        else if (board[x][y] == 4)
        {
            check({x, y}, dir);
            check({x, y}, dir + 1);
            check({x, y}, dir + 2);
        }
        else if (board[x][y] == 5)
        {
            check({x, y}, dir);
            check({x, y}, dir + 1);
            check({x, y}, dir + 2);
            check({x, y}, dir + 3);
        }

        solve(idx + 1);

        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                board[r][c] = backup[r][c];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> row >> col;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            int tmp = 0;
            cin >> tmp;
            board[r][c] = tmp;
            if (tmp > 0 && tmp < 6) cctv.push_back({r, c});
        }
    }

    solve(0);
    cout << min_zero;

    return 0;
}

// 참고: https://seokjin2.tistory.com/108