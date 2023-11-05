#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int n;
ll m;
ll arr[10005];
ll sum_arr[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;

    sort(arr, arr+n);

    sum_arr[0] = arr[0];
    for (int i = 1; i < n; i++)
        sum_arr[i] = sum_arr[i-1] + arr[i];

    ll limit = 0;
    for (int i = 0; i < n; i++)
    {
        limit = arr[i];
        if (sum_arr[i] + (limit * (n-i-1)) > m)
        {
            limit = (m - sum_arr[i-1]) / (n-i);
            break;
        }
    }
    cout << limit;

    return 0;
}