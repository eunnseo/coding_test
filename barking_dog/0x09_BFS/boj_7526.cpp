#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int T, I;
pair<int, int> start;
pair<int, int> fin;
int dis[301][301];

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> I;
        cin >> start.X >> start.Y;
        cin >> fin.X >> fin.Y;

        // clear
        for (int i = 0; i < I; i++)
            for (int j = 0; j < I; j++)
                dis[i][j] = 0;

        queue<pair<int, int>> Q;
        Q.push(start);
        dis[start.X][start.Y] = 1;

        bool ok = false;
        while (!Q.empty())
        {
            pair<int, int> curr = Q.front();
            Q.pop();
            int curr_dis = dis[curr.X][curr.Y];

            // cout << "curr = (" << curr.X << ", " << curr.Y << ")" << endl;
            
            for (int i = 0; i < 8; i++)
            {
                int nx = curr.X + dx[i];
                int ny = curr.Y + dy[i];

                if (nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
                if (dis[nx][ny] != 0) continue;

                Q.push({nx, ny});
                dis[nx][ny] = curr_dis + 1;

                if (fin.X == nx && fin.Y == ny)
                {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        // cout << "------------------------" << endl;
        // cout << dis[fin.X][fin.Y] - 1 << endl;
        cout << dis[fin.X][fin.Y] - 1 << "\n";
    }

    return 0;
}