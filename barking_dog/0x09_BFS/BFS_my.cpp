#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int board[502][502] = 
    {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    int n = 7;
    int m = 10;

    vis[0][0] = 1;
    Q.push({0, 0});

    while (!Q.empty())
    {
        pair<int, int> curr = Q.front();
        Q.pop();
        cout << "(" << curr.X << ", " << curr.Y << ") -> ";

        for (int i = 0; i < 4; i++)
        {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 1 || vis[nx][ny] == 1) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    cout << endl;

    return 0;
}