#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int row, col;
string map[1002];
int dis[2][1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void printDis()
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cout << dis[0][r][c] << " ";
        }
        cout << endl;
    }
    cout << "--------------" << endl;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cout << dis[1][r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

int bfs()
{
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, 0});
    dis[0][0][0] = 1;

    while (!Q.empty())
    {
        pair<pair<int, int>, int> curr = Q.front();
        Q.pop();
        int crash = curr.Y;

        // printDis();
        // cout << "curr = (" << curr.X.X << ", " << curr.X.Y << ") / " << curr.Y << endl;
        // cout << endl;
        // cout << endl;

        if ((curr.X.X == row - 1) && (curr.X.Y == col - 1))
            return dis[crash][curr.X.X][curr.X.Y];

        for (int i = 0; i < 4; i++)
        {
            int nx = curr.X.X + dx[i];
            int ny = curr.X.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;

            if (dis[crash][nx][ny] == 0)
            {
                // 다음 칸이 벽이고 뚫을 수 있을 때
                if (map[nx][ny] == '1' && crash == 0)
                {
                    Q.push({{nx, ny}, 1});
                    dis[1][nx][ny] = dis[0][curr.X.X][curr.X.Y] + 1;
                }
                // 다음 칸이 0이고 방문하지 않았을 때
                else if (map[nx][ny] == '0')
                {
                    Q.push({{nx, ny}, crash});
                    dis[crash][nx][ny] = dis[crash][curr.X.X][curr.X.Y] + 1;
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> row >> col;
    for (int r = 0; r < row; r++)
        cin >> map[r];

    cout << bfs();

    return 0;
}