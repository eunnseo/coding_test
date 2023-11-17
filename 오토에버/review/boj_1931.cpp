#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100005];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + n, cmp);

    pair<int, int> cur = arr[0];
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (cur.second <= arr[i].first)
        {
            cur = arr[i];
            res++;
        }
    }
    cout << res;

    return 0;
}