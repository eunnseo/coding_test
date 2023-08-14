#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m_cnt;
    int res = 0;
    deque<int> DQ;

    cin >> n >> m_cnt;
    for (int i = 1; i <= n; i++)
    {
        DQ.push_back(i);
    }
    for (int i = 0; i < m_cnt; i++)
    {
        int m;
        cin >> m;

        int idx = 0;
        while (m != DQ.front())
        {
            int tmp = DQ.front();
            DQ.pop_front();
            DQ.push_back(tmp);
            idx++;
        }
        DQ.pop_front();

        if (idx < DQ.size() - idx + 1)
            res += idx;
        else
            res += (DQ.size() - idx + 1);
    }

    cout << res;

    return 0;
}