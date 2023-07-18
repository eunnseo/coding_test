#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

string board[102];
int vis[502][502];
int dis[502][502];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vis[0][0] = 1;
    dis[0][0] = 1;

    while (!Q.empty())
    {
        pair<int, int> curr = Q.front();
        Q.pop();

        int curr_dis = dis[curr.X][curr.Y];

        for (int i = 0; i < 4; i++)
        {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '0' || vis[nx][ny] == 1) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});

            dis[nx][ny] = curr_dis + 1;
        }
    }

    cout << dis[n-1][m-1] << "\n";

    return 0;
}