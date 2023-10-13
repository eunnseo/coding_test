#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    sort(a, a+n);

    while (m--)
    {
        int target;
        cin >> target;
        cout << binary_search(a, a+n, target) << "\n";
    }

    return 0;
}