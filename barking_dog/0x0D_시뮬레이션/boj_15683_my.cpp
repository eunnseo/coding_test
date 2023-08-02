#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

int row, col;
int min_zero = 64;
int board[10][10];
vector<pair<int, int>> cctv_pos;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfsCheck(pair<int, int> curr, int dir)
{
    dir %= 4;
    while (1)
    {
        int nx = curr.X + dx[dir];
        int ny = curr.Y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= row || ny >= col) return;
        if (board[nx][ny] == 6) return;
        if (board[nx][ny] != 0) continue;

        board[nx][ny] = -1;
        curr = {nx, ny};
    }
}

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

void run(int idx)
{
    cout << "idx = " << idx << endl;

    if (idx == cctv_pos.size())
    {
        cout << "board: " << endl;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                cout << board[r][c] << " ";
            }
            cout << "\n";
        }
        
        int n_zero = countZero();
        if (n_zero < min_zero) min_zero = n_zero;
        return;
    }

    int x = cctv_pos[idx].X;
    int y = cctv_pos[idx].Y;
    
    for (int dir = 0; dir < 4; dir++)
    {
        int backup[10][10];
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                backup[r][c] = board[r][c];

        if (board[x][y] == 1)
        {
            bfsCheck({x, y}, dir);
        }
        else if (board[x][y] == 2)
        {
            bfsCheck({x, y}, dir);
            bfsCheck({x, y}, dir+2);
        }
        else if (board[x][y] == 3)
        {
            bfsCheck({x, y}, dir);
            bfsCheck({x, y}, dir+1);
        }
        else if (board[x][y] == 4)
        {
            bfsCheck({x, y}, dir);
            bfsCheck({x, y}, dir+1);
            bfsCheck({x, y}, dir+2);
        }
        else if (board[x][y] == 5)
        {
            bfsCheck({x, y}, dir);
            bfsCheck({x, y}, dir+1);
            bfsCheck({x, y}, dir+2);
            bfsCheck({x, y}, dir+3);
        }

        run(idx + 1);

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
            if (tmp > 0 && tmp < 6) cctv_pos.push_back({r, c});
        }
    }

    run(0);
    cout << min_zero;

    return 0;
}