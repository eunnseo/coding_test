#include <iostream>
using namespace std;

using ll = long long;

ll n, s;
ll input[25];
ll arr[25];
int res = 0;

void bfs(int idx, int st, int len)
{
    if (idx == len)
    {
        ll sum_n = 0;
        for (ll i = 0; i < len; i++)
            sum_n += input[arr[i]];
        if (sum_n == s)
            res++;
        return;
    }

    for (ll i = st; i < n; i++)
    {
        arr[idx] = i;
        bfs(idx+1, i+1, len);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> input[i];
        if (input[i] == s)
            res++;
    }

    for (int i = 2; i <= n; i++)
        bfs(0, 0, i);

    cout << res;

    return 0;
}