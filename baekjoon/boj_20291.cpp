#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> res;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string file;
        cin >> file;

        int idx = file.find(".");
        // string name = file.substr(0, idx);
        string ext = file.substr(idx+1);
        // cout << "name = " << name << endl;
        // cout << "ext = " << ext << endl;

        if (res.find(ext) != res.end())
        {
            res[ext]++;
        }
        else
        {
            res[ext] = 1;
        }
    }

    for (auto x : res)
    {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}