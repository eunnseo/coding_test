#include <iostream>
using namespace std;

int n;
int arr[2005];
int DP[2005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        DP[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }
    int max_n = 0;
    for (int i = 0; i < n; i++)
        max_n = max(max_n, DP[i]);
    cout << n - max_n;

    return 0;
}