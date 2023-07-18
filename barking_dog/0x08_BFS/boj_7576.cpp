#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int vis[1002][1002];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;

    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                Q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    int day = 0;
    while(!Q.empty())
    {
        day++;
        int welldone = Q.size();
        for (int i = 0; i < welldone; i++)
        {
            pair<int, int> curr = Q.front();
            Q.pop();

            for (int j = 0; j < 4; j++)
            {
                int nx = curr.X + dx[j];
                int ny = curr.Y + dy[j];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] != 0 || vis[nx][ny] == 1) continue;

                Q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 && vis[i][j] == 0)
            {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << day - 1 << "\n";
    return 0;
}
