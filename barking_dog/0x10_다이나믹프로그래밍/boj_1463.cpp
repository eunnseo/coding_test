#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000002];

int dp(int n)
{
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i-1] + 1;
        if (i % 2 == 0) arr[i] = min(arr[i/2] + 1, arr[i]);
        if (i % 3 == 0) arr[i] = min(arr[i/3] + 1, arr[i]);
    }
    return arr[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << dp(n) << "\n";

    return 0;
}