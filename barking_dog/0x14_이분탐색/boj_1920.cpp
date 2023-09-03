#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    vector<int> A;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    cin >> m;
    
    sort(A.begin(), A.end());

    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        cout << binary_search(A.begin(), A.end(), tmp) << "\n";
    }

    return 0;
}