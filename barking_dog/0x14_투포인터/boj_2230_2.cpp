#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100002];
int min_val = 0x7fffffff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int left = 0;
    int right = 0;
    while (left < n && right < n)
    {
        int diff = arr[right] - arr[left];
        if (diff > m)
        {
            min_val = min(min_val, diff);
            left++;
        }
        else if (diff < m)
        {
            right++;
        }
        else
        {
            min_val = m;
            break;
        }
    }
    cout << min_val;

    return 0;
}