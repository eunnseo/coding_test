#include <iostream>
using namespace std;

typedef long long ll;

int dx[3] = {-1, 0, 1};

int n, m;
int board[10][10];
int arr[10];

int res = 10000;

void dfs(int row)
{
    if (row == n)
    {
        int tmp = 0;
        for (int i = 0; i < n; i++)
            tmp += board[i][arr[i]];
        res = min(res, tmp);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (dx[i] + arr[row-1] < 0 || dx[i] + arr[row-1] >= m) continue;
        if (row > 1 && arr[row-1] - arr[row-2] == dx[i]) continue;

        arr[row] = arr[row-1] + dx[i];
        dfs(row + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < m; i++)
    {
        arr[0] = i;
        dfs(1);
    }

    cout << res;

    return 0;
}