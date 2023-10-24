#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int k, l;
unordered_map<string, int> arr;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> l;
    for (int i = 0; i < l; i++)
    {
        string tmp;
        cin >> tmp;

        if (arr.find(tmp) != arr.end())
        {
            arr.erase(tmp);
            arr[tmp] = i;
        }
        else
        {
            arr[tmp] = i;
        }
    }

    vector<pair<string, int>> v(arr.begin(), arr.end());
    sort(v.begin(), v.end(), cmp);

    int en = min(k, (int)v.size());
    for (int i = 0; i < en; i++)
    {
        cout << v[i].first << "\n";
    }

    return 0;
}