#include <iostream>
using namespace std;

#define MAX_BLK 256
using ll = long long;

int n, m;
ll b;
int board[505][505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int to_remove = 0;
    int to_add = 0;

    while (1)
    {
    }

    return 0;
}