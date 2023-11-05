#include <iostream>
using namespace std;

using ll = long long;

int n;
ll input[10];
int arr[10];
bool isused[10];
ll max_res = 0;

ll calc()
{
    ll res = 0;
    for (int i = 0; i < n-1; i++)
        res += abs(input[arr[i]] - input[arr[i+1]]);
    return res;
}

void dfs(int idx)
{
    if (idx == n)
    {
        ll tmp = calc();
        if (tmp > max_res)
            max_res = tmp;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            arr[idx] = i;
            dfs(idx + 1);
            isused[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> input[i];

    dfs(0);

    cout << max_res;

    return 0;
}