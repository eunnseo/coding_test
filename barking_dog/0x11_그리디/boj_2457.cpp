#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<pair<int, int>, pair<int, int>> flowers[100002];

void INPUT()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> flowers[i].first.first >> flowers[i].first.second >> flowers[i].second.first >> flowers[i].second.second;
}

bool cmp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
    if (a.second.first == b.second.first)
    {
        if (a.second.second == b.second.second)
        {
            if (a.first.first == b.first.first)
            {
                return a.first.second < b.first.second; // 4
            }
            return a.first.first < b.first.first; // 3
        }
        return a.second.second < b.second.second; // 2
    }
    return a.second.first < b.second.first; // 1
}

bool isASmaller(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int OUTPUT()
{
    sort(flowers, flowers + n, cmp);
    pair<int, int> st = {3, 1};
    pair<int, int> en = {11, 30};

    for (int i = 0; i < n; i++)
    {

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    INPUT();


    return 0;
}