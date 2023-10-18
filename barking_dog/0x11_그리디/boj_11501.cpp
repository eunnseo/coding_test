#include <iostream>
using namespace std;

int t, n;
long long int arr[1000002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long int money = 0;
        long long int cnt = 0;
        long long int max_num = arr[n-1];

        for (int i = n-2; i >= 0; i--)
        {
            // cout << "arr[i] = " << arr[i] << endl;
            // cout << "money = " << money << endl;
            // cout << "cnt = " << cnt << endl;
            // cout << "max_num = " << max_num << endl;
            // cout << endl;
            if (max_num >= arr[i]) // 1. buy
            {
                // cout << "1. buy" << endl;
                money -= arr[i];
                cnt++;
            }
            else // 2. sell
            {
                // cout << "2. sell" << endl;
                money += (cnt * max_num);
                cnt = 0;
                max_num = arr[i];
            }
        }
        // cout << "money = " << money << endl;
        // cout << "cnt = " << cnt << endl;
        // cout << "max_num = " << max_num << endl;
        // cout << endl;
        // cout << "==============" << endl;
        money += (cnt * max_num);
        cout << money << "\n";
        // cout << endl;
    }

    return 0;
}