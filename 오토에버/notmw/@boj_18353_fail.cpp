#include <iostream>
using namespace std;

typedef long long ll;

int n;
ll arr[2005];
ll DP[2005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    DP[0] = 1;
    ll res = 0;
    for (int i = 1; i < n; i++)
    {
        ll max_dp = 0;
        int idx = 0;
        bool found = false;
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] < arr[j]) && (max_dp <= DP[j]))
            {
                max_dp = DP[j];
                idx = j;
                found = true;
            }
        }
        if (found)
            DP[i] = DP[idx] + 1;
        else
            DP[i] = 1;

        res = max(DP[i], res);
    }

    for (int i = 0; i < n; i++)
        cout << DP[i] << " ";
    cout << endl;
    cout << endl;

    cout << n - res;

    return 0;
}

// ref: https://codecollector.tistory.com/1182