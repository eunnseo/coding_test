#include <iostream>
using namespace std;

using ll = long long;

int n;
ll arr[1005];
ll D[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        D[i] = 1;
    }

    ll res = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                D[i] = max(D[i], D[j] + 1);
            }
        }

        if (D[i] > res) res = D[i];
    }

    cout << res;
    return 0;
}