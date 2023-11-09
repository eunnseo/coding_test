#include <iostream>
using namespace std;

int n, m;
int board[1005][1005];
int DP[1005][1005];
int res;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    

    return 0;
}