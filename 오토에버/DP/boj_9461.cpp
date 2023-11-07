#include <iostream>
using namespace std;

using ll = long long;

ll DP[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;
    for (int i = 6; i <= 100; i++)
    {
        DP[i] = DP[i-1] + DP[i-5];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << DP[n] << "\n";
    }

    return 0;
}