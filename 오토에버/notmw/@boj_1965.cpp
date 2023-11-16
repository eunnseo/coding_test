#include <iostream>
using namespace std;

int n;
int arr[1005];
int DP[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    DP[0] = 0;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                DP[i] = max(DP[i], DP[j] + 1);
                res = max(res, DP[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << DP[i] << " ";
    cout << endl;

    cout << res + 1;

    return 0;
}