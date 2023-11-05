#include <iostream>
using namespace std;

int n, m;
int arr[100005];
int sum_arr[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sum_arr[0] = arr[0];
    for (int i = 1; i < n; i++)
        sum_arr[i] = sum_arr[i-1] + arr[i];

    cin >> m;
    while (m--)
    {
        int st, en;
        cin >> st >> en;
        if (st == 1)
            cout << sum_arr[en-1] << "\n";
        else
            cout << sum_arr[en-1] - sum_arr[st-2] << "\n";
    }

    return 0;
}