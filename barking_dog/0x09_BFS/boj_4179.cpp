#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

string board[1002];
int dist_J[1002][1002];
int dist_F[1002][1002];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q_J;
    queue<pair<int, int>> Q_F;

    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> board[i];
        for (int j = 0; j < C; j++)
        {
            dist_J[i][j] = -1;
            dist_F[i][j] = -1;

            if (board[i][j] == 'J')
            {
                dist_J[i][j] = 0;
                Q_J.push({i, j});
            }
            if (board[i][j] == 'F')
            {
                dist_F[i][j] = 0;
                Q_F.push({i, j});
            }
        }
    }

    while (!Q_F.empty())
    {
        pair<int, int> curr = Q_F.front();
        Q_F.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (board[nx][ny] == '#' || dist_F[nx][ny] >= 0) continue;

            Q_F.push({nx, ny});
            dist_F[nx][ny] = dist_F[curr.X][curr.Y] + 1;
        }
    }

    while (!Q_J.empty())
    {
        pair<int, int> curr = Q_J.front();
        Q_J.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                cout << dist_J[curr.X][curr.Y] + 1 << "\n";
                return 0;
            }
            if (board[nx][ny] == '#' || dist_J[nx][ny] >= 0) continue;
            if ((dist_F[nx][ny] != -1) && (dist_F[nx][ny] <= dist_J[curr.X][curr.Y] + 1)) continue;

            Q_J.push({nx, ny});
            dist_J[nx][ny] = dist_J[curr.X][curr.Y] + 1;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}