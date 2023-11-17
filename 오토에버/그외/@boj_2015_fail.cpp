#include <iostream>
using namespace std;

typedef long long ll;

ll n, k;
ll arr[200005];
ll sum_arr[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    sum_arr[1] = arr[1];
    for (ll i = 2; i <= n; i++)
        sum_arr[i] = sum_arr[i-1] + arr[i];

    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j++)
        {
            if (sum_arr[j] - sum_arr[i-1] == k)
                res++;
        }
    }
    cout << res;

    return 0;
}