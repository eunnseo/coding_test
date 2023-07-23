#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[102][102][102];
int dist[102][102][102];
int dx[6] = {-1, 0, 0, 1, 0, 0};
int dy[6] = {0, -1, 0, 0, 1, 0};
int dz[6] = {0, 0, -1, 0, 0, 1};

void printDist(int height, int row, int col)
{
    cout << "printDist..\n";
    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                cout << dist[h][r][c] << " ";
            }
            cout << "\n";
        }
        cout << "---\n";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int col, row, height; // col = m, row = n, height = h
    cin >> col >> row >> height;
    int cnt_zero = 0;
    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                cin >> board[h][r][c];
                dist[h][r][c] = -1;
                if (board[h][r][c] == 0) cnt_zero++;
            }
        }
    }
    if (cnt_zero == 0)
    {
        cout << "0";
        return 0;
    }

    queue<int> height_Q;
    queue<pair<int, int>> Q;
    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (board[h][r][c] != 1 || dist[h][r][c] >= 0) continue;

                Q.push({r, c});
                height_Q.push(h);
                dist[h][r][c] = 0;

                while(!Q.empty())
                {
                    pair<int, int> curr = Q.front();
                    Q.pop();
                    int curr_z = height_Q.front();
                    height_Q.pop();
                    cout << "(" << curr.X << ", " << curr.Y << ", " << curr_z << ")" << endl;

                    for (int i = 0; i < 6; i++)
                    {
                        int nx = curr.X + dx[i];
                        int ny = curr.Y + dy[i];
                        int nz = curr_z + dz[i];

                        if (nx < 0 || nx >= row || ny < 0 || ny >= col || nz < 0 || nz >= height) continue;
                        if (board[nz][nx][ny] != 0 || dist[nz][nx][ny] >= 0) continue;

                        Q.push({nx, ny});
                        height_Q.push(nz);
                        dist[nz][nx][ny] = dist[curr_z][curr.X][curr.Y] + 1;
                    }

                    printDist(height, row, col);
                }
            }
        }
    }

    int max_days = 0;
    for (int h = 0; h < height; h++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (board[h][r][c] == 0 && dist[h][r][c] == -1)
                {
                    cout << "-1";
                    return 0;
                }
                if (dist[h][r][c] > max_days) max_days = dist[h][r][c];
            }
        }
    }
    cout << max_days;
    return 0;
}

// 반례: 토마토를 하나씩 bfs를 돌리는 것이 아닌, 모든 토마토를 동시에 bfs를 돌려야 최소 시간을 구할 수 있음

// Input
// 4 1 1
// 1 0 0 1

// Output
// 2

// Answer
// 1
