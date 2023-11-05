#include <iostream>
using namespace std;

using ll = long long;

ll n;
ll k;
ll arr[100005];
ll sum_arr[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (ll i = 0; i < n; i++) cin >> arr[i];

    for (ll i = 0; i < k; i++)
        sum_arr[0] += arr[i];
    
    ll max_num = sum_arr[0];
    for (ll i = 1; i <= n-k; i++)
    {
        sum_arr[i] = sum_arr[i-1] - arr[i-1] + arr[i+k-1];
        if (max_num < sum_arr[i])
            max_num = sum_arr[i];
    }

    cout << max_num;

    return 0;
}