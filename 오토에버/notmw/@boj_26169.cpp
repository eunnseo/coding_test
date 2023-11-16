#include <iostream>
using namespace std;

#define X first
#define Y second

int r, c;
int board[6][6];
int vis[6][6];
pair<int, int> arr[4];

bool ok = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int idx, int apple)
{
    if (idx == 4)
    {
        if (apple >= 2)
            ok = true;
        return;
    }

    pair<int, int> cur = arr[idx-1];
    for (int i = 0; i < 4; i++)
    {
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if (board[nx][ny] == -1 || vis[nx][ny] == 1) continue;

        vis[nx][ny] = 1;
        arr[idx] = {nx, ny};
        if (board[nx][ny] == 1)
        {
            dfs(idx+1, apple+1);
        }
        else
        {
            dfs(idx+1, apple);
        }
        vis[nx][ny] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    cin >> r >> c;

    arr[0] = {r, c};
    vis[r][c] = 1;

    dfs(1, 0);

    if (ok) cout << "1";
    else cout << "0";

    return 0;
}