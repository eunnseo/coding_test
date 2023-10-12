#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[53];
int b[53];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a+n);
    sort(b, b+n, cmp);

    int res1 = 0;
    for (int i = 0; i < n; i++)
    {
        res1 += (a[i] * b[i]);
    }
    cout << res1 << endl;

    return 0;
}