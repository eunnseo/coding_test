#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

#define X first
#define Y second

string board[102];
int vis[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> board[i];
    
    int row = N;
    int col = board[0].length();
    int RGsaekyak = 0;
    int not_RGsaekyak = 0;

    queue<pair<int, int>> Q;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (vis[i][j] == 1) continue;

            Q.push({i, j});
            vis[i][j] = 1;
            char color = board[i][j];
            not_RGsaekyak++;

            while (!Q.empty())
            {
                pair<int, int> curr = Q.front();
                Q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = curr.X + dx[k];
                    int ny = curr.Y + dy[k];

                    if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                    if (vis[nx][ny] == 1 || color != board[nx][ny]) continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            vis[i][j] = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (vis[i][j] == 1) continue;

            Q.push({i, j});
            vis[i][j] = 1;
            char color = board[i][j];
            RGsaekyak++;

            while (!Q.empty())
            {
                pair<int, int> curr = Q.front();
                Q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = curr.X + dx[k];
                    int ny = curr.Y + dy[k];

                    if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                    if (vis[nx][ny] == 1) continue;
                    if ((color == 'B' || board[nx][ny] == 'B') && (color != board[nx][ny])) continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << not_RGsaekyak << " " << RGsaekyak << "\n";

    return 0;
}