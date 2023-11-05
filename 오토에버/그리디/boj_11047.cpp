#include <iostream>
using namespace std;

int n, k;
int arr[15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int res = 0;
    for (int i = n-1; i >= 0; i--)
    {
        int cnt = (k / arr[i]);
        if (cnt > 0)
        {
            res += cnt;
            k %= arr[i];
        }
    }
    cout << res;

    return 0;
}