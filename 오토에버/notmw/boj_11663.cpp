#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int points[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> points[i];
    
    sort(points, points+n);

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        int st = lower_bound(points, points + n, x) - points;
        int en = upper_bound(points, points + n, y) - points;
        cout << en - st << "\n";
    }

    return 0;
}