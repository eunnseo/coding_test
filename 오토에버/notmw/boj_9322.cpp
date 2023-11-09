#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> key1;
int key2_idx[1005];
string pw[1005];
string solved[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            key1[s] = i;
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            key2_idx[i] = key1[s];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> pw[i];
        }

        for (int i = 0; i < n; i++)
        {
            solved[key2_idx[i]] = pw[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << solved[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}