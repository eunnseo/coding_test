#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<pair<int, int>> arr;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        bool found = false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (tmp == arr[i].first)
            {
                arr[i].second++;
                found = true;
                break;
            }
        }
        if (!found)
            arr.push_back({tmp, 1});
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].second; j++)
        {
            cout << arr[i].first << " ";
        }
    }

    return 0;
}