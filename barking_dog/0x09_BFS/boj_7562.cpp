#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int board[301][301];
int dist[301][301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, I;
    pair<int, int> start;
    pair<int, int> end;
    
    cin >> T;
    while (T--)
    {
        cin >> I;

        int x, y;
        cin >> x >> y;
        start = {x, y};
        cin >> x >> y;
        end = {x, y};

        queue<pair<int, int>> Q;
        Q.push(start);

        bool ok = false;
        while (!Q.empty())
        {
            pair<int, int> curr = Q.front();
            Q.pop();

            int curr_dist = dist[curr.X][curr.Y];

            for (int i = 0; i < 8; i++)
            {
                int nx = start.X + dx[i];
                int ny = start.Y + dy[i];

                if (nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
                if (dist[nx][ny] != 0) continue;

                dist[nx][ny] = curr_dist + 1;

                if (end.X == nx && end.Y == ny)
                {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        cout << dist[end.X][end.Y] << "\n";
    }

    return 0;
}