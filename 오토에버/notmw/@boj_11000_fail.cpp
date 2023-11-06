#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        arr.push_back({s, t});
    }

    sort(arr.begin(), arr.end(), cmp);

    int res = 0;
    vector<int> erase_idx;

    while (!arr.empty())
    {
        res++;

        pair<int, int> cur = arr[0];
        erase_idx.push_back(0);

        for (int i = 1; i < arr.size(); i++)
        {
            if (cur.second <= arr[i].first)
            {
                cur = arr[i];
                erase_idx.push_back(i);
            }
        }

        for (int i = 0; i < erase_idx.size(); i++)
        {
            arr.erase(arr.begin() + erase_idx[i]);
        }
        erase_idx.clear();
    }
    cout << res;

    return 0;
}