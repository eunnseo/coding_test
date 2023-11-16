#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
#define MAX_N 5

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int board[6][6];
int dist[6][6];
int apple[6][6];
pair<int, int> st;

void print()
{
    cout << "board > " << endl;
    for (int i = 0; i < MAX_N; i++)
    {
        for (int j = 0; j < MAX_N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "dist > " << endl;
    for (int i = 0; i < MAX_N; i++)
    {
        for (int j = 0; j < MAX_N; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "apple > " << endl;
    for (int i = 0; i < MAX_N; i++)
    {
        for (int j = 0; j < MAX_N; j++)
        {
            cout << apple[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "============================" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            cin >> board[i][j];
    cin >> st.X >> st.Y;

    queue<pair<int, int>> Q;
    Q.push(st);
    dist[st.X][st.Y] = 0;

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        board[cur.X][cur.Y] = -1;

        // cout << "cur = (" << cur.X << ", " << cur.Y << ")" << endl;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= MAX_N || ny >= MAX_N) continue;
            if (board[nx][ny] == -1) continue;
            if (dist[cur.X][cur.Y] == 3) continue;

            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;

            if (board[nx][ny] == 1)
            {
                apple[nx][ny] = apple[cur.X][cur.Y] + 1;
                if (apple[nx][ny] == 2)
                {
                    cout << "1";
                    return 0;
                }
            }
            else
            {
                apple[nx][ny] = apple[cur.X][cur.Y];
            }
        }

        // print();
    }

    cout << "0";
    return 0;
}