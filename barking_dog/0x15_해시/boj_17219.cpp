#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> note;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string site, pw;
        cin >> site >> pw;
        note[site] = pw;
    }

    for (int i = 0; i < m; i++)
    {
        string site;
        cin >> site;
        auto iter = note.find(site);
        cout << iter->second << "\n";
    }


    return 0;
}