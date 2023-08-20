#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int board[102][102];
int vis[102][102];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int row, col, k;
    vector<int> res;

    cin >> row >> col >> k;

    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        y1 = row - y1;
        y2 = row - y2;

        for (int r = y2; r < y1; r++)
            for (int c = x1; c < x2; c++)
                board[r][c] = 1;
    }

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (board[r][c] == 1 || vis[r][c] == 1) continue;

            queue<pair<int, int>> Q;
            Q.push({r, c});
            vis[r][c] = 1;
            int cnt = 1;
            
            while (!Q.empty())
            {
                pair<int, int> curr = Q.front();
                Q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = curr.X + dx[i];
                    int ny = curr.Y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
                    if (board[nx][ny] == 1 || vis[nx][ny] == 1) continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                    cnt++;
                }
            }

            res.push_back(cnt);
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}