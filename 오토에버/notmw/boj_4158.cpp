#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

ll n, m;
ll sang[1000005];
ll sun[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (ll i = 0; i < n; i++) cin >> sang[i];
        for (ll i = 0; i < m; i++) cin >> sun[i];

        int sang_i = 0;
        int sun_i = 0;
        int res = 0;

        while (1)
        {
            if (sang_i >= n || sun_i >= m) break;

            if (sun[sun_i] < sang[sang_i])
            {
                sun_i++;
            }
            else if (sun[sun_i] == sang[sang_i])
            {
                res++;
                sun_i++;
                sang_i++;
            }
            else if (sun[sun_i] > sang[sang_i])
            {
                sang_i++;
            }
            else
            {
                /* do nothing */
            }
        }

        cout << res << "\n";
    }

    return 0;
}