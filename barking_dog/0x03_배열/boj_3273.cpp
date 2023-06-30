// 두 수의 합
#include <iostream>
using namespace std;

int arr[1000001] = { 0, };
bool occur[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* my solution: 시간초과 */
    // int n;
    // int x;

    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cin >> x;

    // int cnt = 0;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] + arr[j] == x)
    //         {
    //             cnt++;
    //         }
    //     }
    // }

    // cout << cnt << "\n";

    /* barkingdog solution */
    int n, x;
    int cnt = 0;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (x - arr[i] > 0 && occur[x - arr[i]])
        {
            cnt++;
        }
        occur[arr[i]] = true;
    }

    cout << cnt << "\n";

    return 0;
}