#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
ll arr[500005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (ll i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        res += abs(arr[i] - (i+1));
    }
    cout << res;

    return 0;
}