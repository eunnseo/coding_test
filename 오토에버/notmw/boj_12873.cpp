#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n = 0;
    ll t = 1;
    queue<ll> Q;

    cin >> n;
    for (ll i = 1; i <= n; i++)
        Q.push(i);

    while (1)
    {
        if (Q.size() == 1) break;

        ll rm_num = pow(t, 3) - 1;
        rm_num %= Q.size();
        while (rm_num--)
        {
            ll tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }
        Q.pop();

        t++;
    }
    cout << Q.front();

    return 0;
}