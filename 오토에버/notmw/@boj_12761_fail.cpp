#include <iostream>
using namespace std;

#define MAX_N 100000

int a, b, n, m;
int DP[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> n >> m;
    for (int i = 0; i <= MAX_N; i++) DP[i] = MAX_N;

    DP[n] = 0;
    for (int i = 0; i <= MAX_N; i++)
    {
        if (i - 1 >= 0)
            DP[i] = min(DP[i-1] + 1, DP[i]);
        if (i + 1 <= MAX_N)
            DP[i] = min(DP[i+1] + 1, DP[i]);

        if (i - a >= 0)
            DP[i] = min(DP[i-a] + 1, DP[i]);
        if (i + a <= MAX_N)
            DP[i] = min(DP[i+a] + 1, DP[i]);

        if (i - b >= 0)
            DP[i] = min(DP[i-b] + 1, DP[i]);
        if (i + b <= MAX_N)
            DP[i] = min(DP[i+b] + 1, DP[i]);

        if (i % a == 0)
            DP[i] = min(DP[i/a] + 1, DP[i]);
        if (i % b == 0)
            DP[i] = min(DP[i/b] + 1, DP[i]);
    }

    for (int i = 0; i <= m; i++)
    {
        cout << DP[i] << " ";
        if (i % 10 == 0) cout << endl;
    }
    cout << endl;

    // for (int i = n-1; i >= 0; i--)
    // {
    //     if (i - 1 >= 0)
    //         DP[i] = min(DP[i-1] + 1, DP[i]);
    //     if (i + 1 <= MAX_N)
    //         DP[i] = min(DP[i+1] + 1, DP[i]);

    //     if (i - a >= 0)
    //         DP[i] = min(DP[i-a] + 1, DP[i]);
    //     if (i + a <= MAX_N)
    //         DP[i] = min(DP[i+a] + 1, DP[i]);

    //     if (i - b >= 0)
    //         DP[i] = min(DP[i-b] + 1, DP[i]);
    //     if (i + b <= MAX_N)
    //         DP[i] = min(DP[i+b] + 1, DP[i]);

    //     if (i % a == 0)
    //         DP[i] = min(DP[i/a] + 1, DP[i]);
    //     if (i % b == 0)
    //         DP[i] = min(DP[i/b] + 1, DP[i]);
    // }

    // for (int i = 0; i < 20; i++)
    //     cout << DP[i] << " ";
    // cout << endl;

    cout << DP[m];

    return 0;
}