#include <iostream>
using namespace std;

int n, s;
int arr[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0;
    int right = 0;
    int sum_val = arr[0];
    int res = 0x7fffffff;

    while (left < n && right < n)
    {
        if (sum_val < s)
        {
            right++;
            sum_val += arr[right];
        }
        else
        {
            res = min(res, right - left + 1);
            sum_val -= arr[left];
            left++;
        }
    }

    if (res == 0x7fffffff) res = 0;
    cout << res;
    return 0;
}