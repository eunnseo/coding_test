#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[52][52];
int vis[52][52];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int col, row, K;
        cin >> col >> row >> K;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }

        while (K--)
        {
            int c, r;
            cin >> c >> r;
            board[r][c] = 1;
        }

        // cout << "board..\n";
        // for (int i = 0; i < row; i++)
        // {
        //     for (int j = 0; j < col; j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        int zrung = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] != 1 || vis[i][j] == 1) continue;

                zrung++;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis[i][j] = 1;

                while (!Q.empty())
                {
                    pair<int, int> curr = Q.front();
                    Q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = curr.X + dx[k];
                        int ny = curr.Y + dy[k];

                        if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                        if (board[nx][ny] != 1 || vis[nx][ny] == 1) continue;

                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        cout << zrung << "\n";
    }

    return 0;
}