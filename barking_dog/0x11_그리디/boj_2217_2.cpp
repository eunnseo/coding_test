#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100002];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, cmp);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max((i+1) * arr[i], res);
    }
    cout << res;

    return 0;
}