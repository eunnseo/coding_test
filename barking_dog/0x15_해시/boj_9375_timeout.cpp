#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> m_fashion;
vector<int> v_fashion;

int arr[30];
bool isused[30];

int t, n;
int res = 0;

void dfs(int idx, int st, int arr_size)
{
    if (idx == arr_size)
    {
        // for (int i = 0; i < arr_size; i++)
        //     cout << v_fashion[arr[i]] << " ";
        // cout << endl;
        int tmp = 1;
        for (int i = 0; i < arr_size; i++)
            tmp *= v_fashion[arr[i]];
        res += tmp;
        return;
    }

    for (int i = st; i < v_fashion.size(); i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            arr[idx] = i;
            dfs(idx+1, i, arr_size);
            isused[i] = false;
        }
    }
}

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
        for (auto iter = m_fashion.begin(); iter != m_fashion.end(); iter++)
            v_fashion.push_back(iter->second);

        for (int i = 1; i <= v_fashion.size(); i++)
        {
            dfs(0, 0, i);
            for (int i = 0; i < 30; i++)
            {
                arr[i] = 0;
                isused[i] = 0;
            }
        }
        
        cout << res << "\n";

        m_fashion.clear();
        v_fashion.clear();
        res = 0;
    }

    return 0;
}