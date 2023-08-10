#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int T, col, row;
string board[1002];

int dis_fire[1002][1002];
int dis_sk[1002][1002];

queue<pair<int, int>> Q_fire;
queue<pair<int, int>> Q_sk;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> col >> row;
        for (int i = 0; i < row; i++)
            cin >> board[i];

        // clear
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                dis_fire[i][j] = 0;
                dis_sk[i][j] = 0;
            }
        }
        while (!Q_fire.empty()) Q_fire.pop();
        while (!Q_sk.empty()) Q_sk.pop();
        
        // input
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == '@')
                {
                    Q_sk.push({i, j});
                    dis_sk[i][j] = 1;
                }
                else if (board[i][j] == '*')
                {
                    Q_fire.push({i, j});
                    dis_fire[i][j] = 1;
                }
            }
        }

        // BFS fire
        while (!Q_fire.empty())
        {
            pair<int, int> curr = Q_fire.front();
            Q_fire.pop();
            int curr_dis = dis_fire[curr.X][curr.Y];

            for (int i = 0; i < 4; i++)
            {
                int nx = curr.X + dx[i];
                int ny = curr.Y + dy[i];

                if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
                if (dis_fire[nx][ny] != 0 || board[nx][ny] == '#') continue;

                Q_fire.push({nx, ny});
                dis_fire[nx][ny] = curr_dis + 1;
            }
        }

        // BFS sk
        bool ok = false;
        while (!Q_sk.empty())
        {
            pair<int, int> curr = Q_sk.front();
            Q_sk.pop();
            int curr_dis = dis_sk[curr.X][curr.Y];

            for (int i = 0; i < 4; i++)
            {
                int nx = curr.X + dx[i];
                int ny = curr.Y + dy[i];

                if (nx < 0 || ny < 0 || nx >= row || ny >= col)
                {
                    cout << curr_dis << "\n";
                    ok = true;
                    break;
                }

                if (dis_sk[nx][ny] != 0 || board[nx][ny] == '#') continue;
                if ((dis_fire[nx][ny] != 0) && (curr_dis + 1 >= dis_fire[nx][ny])) continue;

                Q_sk.push({nx, ny});
                dis_sk[nx][ny] = curr_dis + 1;
            }
            if (ok) break;
        }
        if (!ok) cout << "IMPOSSIBLE\n";
    }

    return 0;
}