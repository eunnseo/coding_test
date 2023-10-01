#include <iostream>
using namespace std;

int coin[12];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    int cnt = 0;
    for (int i = n-1; i >= 0; i--)
    {
        int tmp = (k / coin[i]);
        k -= tmp * coin[i];
        cnt += tmp;
    }
    cout << cnt;

    return 0;
}