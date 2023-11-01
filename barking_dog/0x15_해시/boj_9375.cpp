#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m_fashion;
int t, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string name, kind;
            cin >> name >> kind;
            if (m_fashion.find(kind) == m_fashion.end())
            {
                m_fashion[kind] = 1;
            }
            else
            {
                m_fashion[kind]++;
            }
        }

        int res = 1;
        for (auto iter = m_fashion.begin(); iter != m_fashion.end(); iter++)
        {
            res *= (iter->second + 1);
        }
        cout << res - 1 << "\n";

        m_fashion.clear();
    }

    return 0;
}