#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[502][502];
int vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    queue<pair<int, int>> Q;

    int pics_num = 0;
    int pics_area = 0;
    int max_pics_area = 0;
    
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (vis[row][col] == 1 || board[row][col] != 1) continue;

            pics_num++;
            pics_area = 1;

            vis[row][col] = 1;
            Q.push({row, col});

            // BFS
            while (!Q.empty())
            {
                pair<int, int> curr = Q.front();
                Q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = curr.X + dx[i];
                    int ny = curr.Y + dy[i];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    pics_area++;
                }
            }

            if (pics_area > max_pics_area)
            {
                max_pics_area = pics_area;
            }
        }
    }

    cout << pics_num << "\n" << max_pics_area;


    return 0;
}