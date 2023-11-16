#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m, t;
int R[1005][1005];
int G[1005][1005];
int B[1005][1005];
int board[1005][1005];
int vis[1005][1005];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> R[i][j] >> G[i][j] >> B[i][j];
        }
    }
    cin >> t;
    t *= 3;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((R[i][j] + G[i][j] + B[i][j]) >= t)
            {
                board[i][j] = 255;
            }
        }
    }
}

void bfs(pair<int, int> st)
{
    queue<pair<int, int>> Q;
    Q.push(st);
    vis[st.X][st.Y] = 1;

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;

            Q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 255 && vis[i][j] == 0)
            {
                bfs({i, j});
                res++;
            }
        }
    }
    cout << res;

    return 0;
}