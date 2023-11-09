#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0) // 아이들
        {
            if (pq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else // 거점지
        {
            for (int j = 0; j < a; j++)
            {
                int value;
                cin >> value;
                pq.push(value);
            }
        }
    }

    return 0;
}
