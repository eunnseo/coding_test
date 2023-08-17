#include <iostream>
using namespace std;

int arr[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int res = -1;
    int n, k;
    cin >> n >> k;

    while (k > 0)
    {
        int p = 0;
        for (int i = 2; i <= n; i++)
        {
            if (arr[i] == 0)
            {
                p = i;
                break;
            }
        }

        int p2 = p;
        while (p2 <= n && k > 0)
        {
            if (arr[p2] == 0)
            {
                k--;
                arr[p2] = 1;
                if (k == 0) res = p2;
            }
            p2 += p;
        }
    }
    cout << res;

    return 0;
}