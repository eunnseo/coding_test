#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> todo;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.Y > b.Y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int d, t;
        cin >> d >> t;
        todo.push_back({d, t});
    }

    sort(todo.begin(), todo.end(), compare);

    int day = todo[0].Y;
    for (int i = 0; i < todo.size(); i++)
    {
        if (day < todo[i].Y)
        {
            day -= todo[i].X;
        }
        else
        {
            day = todo[i].Y - todo[i].X;
        }
    }
    cout << day << "\n";

    return 0;
}