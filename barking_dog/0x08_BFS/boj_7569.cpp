#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define X first
#define Y second

int board[102][102][102];
int dist[102][102][102];
int dx[6] = {-1, 0, 0, 1, 0, 0};
int dy[6] = {0, -1, 0, 0, 1, 0};
int dz[6] = {0, 0, -1, 0, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int col, row, height;
    cin >> col >> row >> height;

    bool has_zero = false;
    queue<pair<int, pair<int, int>>> Q;

    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                int tmp;
                cin >> tmp;
                board[h][r][c] = tmp;
                if (tmp == 1)
                {
                    Q.push({h, {r, c}});
                }
                else if (tmp == 0)
                {
                    has_zero = true;
                    dist[h][r][c] = -1;
                }
            }
        }
    }
    if (!has_zero)
    {
        cout << "0";
        return 0;
    }

    while (!Q.empty())
    {
        pair<int, pair<int, int>> curr = Q.front();
        Q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nz = curr.X + dz[i];
            int nx = curr.Y.X + dx[i];
            int ny = curr.Y.Y + dy[i];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col || nz < 0 || nz >= height) continue;
            if (dist[nz][nx][ny] >= 0) continue;

            Q.push({nz, {nx, ny}});
            dist[nz][nx][ny] = dist[curr.X][curr.Y.X][curr.Y.Y] + 1;
        }
    }

    int max_days = 0;
    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (dist[h][r][c] == -1)
                {
                    cout << "-1";
                    return 0;
                }
                if (dist[h][r][c] > max_days)
                {
                    max_days = dist[h][r][c];
                }
            }
        }
    }
    cout << max_days;
    return 0;
}