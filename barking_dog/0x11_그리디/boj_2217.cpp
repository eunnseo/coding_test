#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int max_w = 0;
    int cnt = n;
    for (int i = 0; i < v.size(); i++)
    {
        max_w = max(max_w, v[i] * cnt);
        cnt--;
    }
    cout << max_w << "\n";

    return 0;
}