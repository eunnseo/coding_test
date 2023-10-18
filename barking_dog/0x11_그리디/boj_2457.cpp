#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<pair<int, int>, pair<int, int>> arr[100002];

bool cmp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return a.first.first < b.first.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;

    sort(arr, arr + n, cmp);

    pair<int, int> std_date = {3, 1};
    pair<int, int> max_date = {0, 0};
    for (int i = 0; i < n; i++)
    {
        cout << "arr[i] = " << arr[i].first.first << " " << arr[i].first.second << " " << arr[i].second.first << " " << arr[i].second.second << endl;
        cout << "std_date = (" << std_date.first << " / " << std_date.second << ")" << endl;
        cout << "max_date = (" << max_date.first << " / " << max_date.second << ")" << endl;
        if (std_date >= arr[i].first)
        {
            if (max_date < arr[i].second)
                max_date = arr[i].second;
        }
        else
        {
            if (max_date.first == 0 && max_date.second == 0)
            {
                cout << "0\n";
                return 0;
            }
            std_date = arr[i-1].first;
            max_date = {0, 0};
        }
    }

    return 0;
}