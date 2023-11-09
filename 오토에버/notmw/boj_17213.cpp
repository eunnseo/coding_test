#include <iostream>
using namespace std;

int n, m;
int arr[35];
long long res = 0;

void dfs(int idx, int st)
{
    int len = m - n;
    if (idx == len)
    {
        // for (int i = 0; i < len; i++)
        //     cout << arr[i] << " ";
        // cout << endl;
        res++;
        return;
    }

    for (int i = st; i < n; i++)
    {
        arr[idx] = i;
        dfs(idx+1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dfs(0, 0);
    cout << res;

    return 0;
}