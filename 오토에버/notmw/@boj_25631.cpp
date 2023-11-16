#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> umap;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (umap.find(tmp) == umap.end())
        {
            umap[tmp] = 1;
        }
        else
        {
            umap[tmp]++;
        }
    }

    int res = 0;
    for (auto iter = umap.begin(); iter != umap.end(); iter++)
    {
        res = max(res, iter->second);
    }
    cout << res;

    return 0;
}