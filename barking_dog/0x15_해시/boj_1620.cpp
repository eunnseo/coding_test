#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int num = 1;
    unordered_map<int, string> i2s;
    unordered_map<string, int> s2i;

    while (n--)
    {
        string name;
        cin >> name;
        i2s[num] = name;
        s2i[name] = num;
        num++;
    }

    while (m--)
    {
        string Q;
        cin >> Q;
        if (isdigit(Q[0]))
        {
            cout << i2s[stoi(Q)] << "\n";
        }
        else
        {
            cout << s2i[Q] << "\n";
        }
    }

    return 0;
}