#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n;
int x[1000002];
set<int> s;
vector<int> v;

void INPUT()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        s.insert(x[i]);
    }
    for (auto x : s)
        v.push_back(x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    INPUT();
    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(v.begin(), v.end(), x[i]) - v.begin() << " ";
    }

    return 0;
}