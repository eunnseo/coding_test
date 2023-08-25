#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> meeting;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.Y == b.Y)
    {
        return a.X < b.X;
    }
    return a.Y < b.Y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        meeting.push_back({a, b});
    }

    sort(meeting.begin(), meeting.end(), compare);

    int cnt = 1;
    pair<int, int> curr = meeting.front();

    for (int i = 1; i < meeting.size(); i++)
    {
        if (curr.Y <= meeting[i].X)
        {
            cnt++;
            curr = meeting[i];
        }
    }
    cout << cnt;

    return 0;
}