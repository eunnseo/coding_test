#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500002];

void INPUT()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    INPUT();

    sort(arr, arr+n);
    while (m--)
    {
        int target;
        cin >> target;
        cout << upper_bound(arr, arr+n, target) - lower_bound(arr, arr+n, target) << "\n";
    }

    return 0;
}