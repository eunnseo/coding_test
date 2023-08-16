#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int res = 0;
    while (n--)
    {
        int k;
        cin >> k;
        
        if (k == 1) continue;

        bool ok = true;
        for (int i = 2; i < k; i++)
        {
            if (k % i == 0)
            {
                ok = false;
                break;
            }
        }
        if (ok) res++;
    }
    cout << res;

    return 0;
}