#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n;
char board[8][8];

vector<pair<int, int>> blank;
vector<pair<int, int>> stu;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'X') blank.push_back({i, j});
            else if (board[i][j] == 'S') stu.push_back({i, j});
        }
    }
}

bool canAvoid(pair<int, int> pos)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = pos.X;
        int ny = pos.Y;

        while (1)
        {
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
            if (board[nx][ny] == 'T') return false;
            else if (board[nx][ny] == 'O') break;

            nx += dx[i];
            ny += dy[i];
        }
    }
    return true;
}

void dfs(int idx, int st)
{
    if (idx == 3)
    {
        for (int i = 0; i < stu.size(); i++)
        {
            if (!canAvoid(stu[i]))
                return;
        }
        cout << "YES\n";
        exit(0);
    }

    for (int i = st; i < blank.size(); i++)
    {
        board[blank[i].X][blank[i].Y] = 'O';
        dfs(idx + 1, i + 1);
        board[blank[i].X][blank[i].Y] = 'X';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    dfs(0, 0);

    cout << "NO\n";

    return 0;
}