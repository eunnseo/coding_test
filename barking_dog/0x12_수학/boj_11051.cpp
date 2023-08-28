#include <iostream>
using namespace std;

long long DP[1002][1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (k > n-k) k = n-k;

    for (int i = 1; i <= n; i++)
    {
        DP[i][0] = 1;
        DP[i][i] = 1;

        DP[i][1] = i;
    }

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= k; j++)
            DP[i][j] = (DP[i-1][j-1] + DP[i-1][j]) % 10007;

    cout << DP[n][k];

    return 0;
}