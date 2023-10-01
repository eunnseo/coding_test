#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<string> giggle;

    int n;
    cin >> n;
    while (n--)
    {
        string name, status;
        cin >> name >> status;
        if (status == "enter")
            giggle.insert(name);
        else
            giggle.erase(name);
    }

    vector<string> ans(giggle.begin(), giggle.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (auto x : ans)
        cout << x << "\n";

    return 0;
}