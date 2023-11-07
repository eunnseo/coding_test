#include <iostream>
using namespace std;

using ll = long long;

int n;
ll S[1005];
ll D[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> S[i];

    for (int i = 0; i < n; i++)
        D[i] = S[i];

    ll res = D[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if (S[j] < S[i])
            {
                D[i] = max(D[i], D[j] + S[i]);
            }
        }

        if (res < D[i])
            res = D[i];
    }

    cout << res;
    return 0;
}

// ref: https://velog.io/@matcha_/%EB%B0%B1%EC%A4%80-11055-%EA%B0%80%EC%9E%A5-%ED%81%B0-%EC%A6%9D%EA%B0%80-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-C-DP