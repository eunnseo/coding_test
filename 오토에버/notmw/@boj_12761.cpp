#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
#define MAX_N 100000

typedef long long ll;

ll a, b, n, m;
ll arr[100005];
int vis[100005];

ll getNX(int idx, ll cur)
{
    if (idx == 0) return cur + 1;
    else if (idx == 1) return cur - 1;
    else if (idx == 2) return cur + a;
    else if (idx == 3) return cur - a;
    else if (idx == 4) return cur + b;
    else if (idx == 5) return cur - b;
    else if (idx == 6) return cur * a;
    else if (idx == 7) return cur * b;
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> n >> m;
    for (int i = 0; i <= MAX_N; i++) arr[i] = MAX_N;

    queue<ll> Q;
    Q.push(n);
    arr[n] = 0;
    vis[n] = 1;

    while (!Q.empty())
    {
        ll cur = Q.front();
        Q.pop();

        for (int i = 0; i < 8; i++)
        {
            ll nx = getNX(i, cur);

            if (nx < 0 || nx > MAX_N) continue;
            if (vis[nx] == 1) continue;

            arr[nx] = min(arr[cur] + 1, arr[nx]);
            vis[nx] = 1;
            Q.push(nx);
        }
    }

    cout << arr[m];

    return 0;
}