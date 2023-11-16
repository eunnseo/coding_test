#include <iostream>
using namespace std;

int n;
int arr[200005];
int dp[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int min_n = arr[0];
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = arr[i] - min_n;
        min_n = min(min_n, arr[i]);
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}