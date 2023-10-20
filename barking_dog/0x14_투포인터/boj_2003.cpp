#include <iostream>
using namespace std;

int n, m;
int arr[10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0;
    int right = 0;
    int sum_val = arr[0];
    int res = 0;

    while (left < n && right < n)
    {
        if (sum_val < m)
        {
            right++;
            sum_val += arr[right];
        }
        else
        {
            if (sum_val == m) res++;
            sum_val -= arr[left];
            left++;
        }
    }
    cout << res;

    return 0;
}