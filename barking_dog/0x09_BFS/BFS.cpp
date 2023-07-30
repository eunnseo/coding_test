#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int board[502][502] =  // 1: 방문할 수 있는 칸, 0: 방문할 수 없는 칸
    {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int vis[502][502]; // 1: 이미 방문한 칸, 0: 아직 방문하지 않은 칸

int dx[4] = {1, 0, -1, 0}; // 시계방향
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 7;
    int m = 10;
    queue<pair<int, int>> Q;

    // 1. 시작하는 칸을 큐에 넣고 방문했다는 표시를 남김
    vis[0][0] = 1;
    Q.push({0, 0});

    while (!Q.empty()) // 큐가 빌 때까지 반복
    {
        // 2. 큐에서 원소를 꺼냄
        pair<int, int> cur = Q.front();
        Q.pop();
        cout << "(" << cur.X << ", " << cur.Y << ") -> ";

        for (int dir = 0; dir < 4; dir++)
        {
            // 3. 상하좌우로 인접한 칸 탐색
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            // 4. 해당 칸을 방문할 것인지 여부 확인
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;

            // 5. 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    cout << endl;

    return 0;
}