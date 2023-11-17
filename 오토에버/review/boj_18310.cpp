#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    if (n % 2 == 0)
        cout << arr[n/2-1];
    else
        cout << arr[n/2];

    return 0;
}