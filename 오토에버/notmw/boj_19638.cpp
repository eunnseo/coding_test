#include <iostream>
#include <queue>
using namespace std;

int n, h, t;
priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> t;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp >= h)
            pq.push(tmp);
    }

    int cnt = 0;
    while (t > 0 && !pq.empty())
    {
        int cur = pq.top();

        if (cur == 1) break;

        t--;
        cnt++;
        pq.pop();
        cur /= 2;
        if (cur >= h)
            pq.push(cur);
    }

    if (pq.empty())
    {
        cout << "YES\n";
        cout << cnt;
    }
    else
    {
        cout << "NO\n";
        cout << pq.top();
    }

    return 0;
}