#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
int board[55][55];
int dist[55][55];

void clearVis()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = 0;
}

int bfs(pair<int, int> st)
{
    if (board[st.X][st.Y] == 1) return 0;

    clearVis();

    queue<pair<int, int>> Q;
    dist[st.X][st.Y] = 1;
    Q.push(st);
    int max_dist = 1;

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] > 0) continue;

            if (board[nx][ny] == 1)
            {
                return dist[cur.X][cur.Y];
            }

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
            max_dist = max(max_dist, dist[nx][ny]);
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int dist = bfs({i, j});
            res = max(res, dist);
        }
    }
    cout << res;

    return 0;
}