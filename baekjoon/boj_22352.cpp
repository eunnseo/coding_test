#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;
int before[32][32];
int after[32][32];
bool vis[32][32];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> before[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> after[i][j];
}

void bfs(pair<int, int> st, int new_data)
{
    int data = before[st.X][st.Y];
    queue<pair<int, int>> Q;
    Q.push(st);
    vis[st.X][st.Y] = 1;
    before[st.X][st.Y] = new_data;

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] == 1 || before[nx][ny] != data) continue;

            Q.push({nx, ny});
            vis[nx][ny] = 1;
            before[nx][ny] = new_data;
        }
    }
}

bool check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (before[i][j] != after[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (before[i][j] != after[i][j])
            {
                bfs({i, j}, after[i][j]);

                if (check()) cout << "YES\n";
                else cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}