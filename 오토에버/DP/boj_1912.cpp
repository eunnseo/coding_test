#include <iostream>
using namespace std;

using ll = long long;

int n;
ll S[100005];
ll D[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> S[i];

    D[0] = S[0];
    ll res = D[0];
    for (int i = 1; i < n; i++)
    {
        D[i] = max(S[i], S[i] + D[i-1]);
        if (res < D[i])
            res = D[i];
    }
    cout << res;
    return 0;
}