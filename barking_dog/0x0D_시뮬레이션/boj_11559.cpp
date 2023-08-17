#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
#define ROW 12
#define COL 6

int res = 0;
string board[ROW];
int vis[ROW][COL];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void clearVis()
{
    for (int r = 0; r < ROW; r++)
        for (int c = 0; c < COL; c++)
            vis[r][c] = 0;
}

bool puyo(pair<int, int> start)
{
    string backup[12];
    for (int r = 0; r < ROW; r++)
        for (int c = 0; c < COL; c++)
            backup[r][c] = board[r][c];

    int cnt_puyo = 0;
    char color = board[start.X][start.Y];

    queue<pair<int, int>> Q;
    Q.push(start);
    board[start.X][start.Y] = '.';
    vis[start.X][start.Y] = 1;

    cnt_puyo++;

    while (!Q.empty())
    {
        pair<int, int> curr = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= ROW || ny >= COL) continue;
            if (board[nx][ny] != color || vis[nx][ny] == 1) continue;

            Q.push({nx, ny});
            board[nx][ny] = '.';
            vis[nx][ny] = 1;
            cnt_puyo++;
        }
    }

    if (cnt_puyo < 4)
    {
        for (int r = 0; r < ROW; r++)
            for (int c = 0; c < COL; c++)
                board[r][c] = backup[r][c];
        return false;
    }
    return true;
}

void drop()
{
    for (int c = 0; c < COL; c++)
    {
        for (int r = ROW-2; r >= 0; r--)
        {
            int tmp = r;

            while (1)
            {
                if (tmp == ROW-1) break;
                if (board[tmp][c] == '.' || board[tmp+1][c] != '.') break;

                board[tmp+1][c] = board[tmp][c];
                board[tmp][c] = '.';
                tmp++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int r = 0; r < ROW; r++)
        cin >> board[r];

    while (1)
    {
        int pung = 0;
        clearVis();

        for (int r = 0; r < ROW; r++)
        {
            for (int c = 0; c < COL; c++)
            {
                if (board[r][c] != '.' && vis[r][c] == 0)
                {
                    if (puyo({r, c})) pung++;
                }
            }
        }

        if (pung == 0) break;

        drop();
        res++;
    }

    cout << res;

    return 0;
}