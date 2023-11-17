#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int max_same_n = 1;
    int same_n = 1;
    int bef_size = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == bef_size)
        {
            same_n++;
        }
        else
        {
            same_n = 1;
        }
        max_same_n = max(max_same_n, same_n);
        bef_size = arr[i];
    }
    cout << max_same_n;

    return 0;
}