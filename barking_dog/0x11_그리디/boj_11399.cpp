#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += ((n-i) * arr[i]);
    }
    cout << res;

    return 0;
}