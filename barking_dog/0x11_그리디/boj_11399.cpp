#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1002];
int arr[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p+n);

    arr[0] = p[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i-1] + p[i];
        res += arr[i];
    }
    cout << res;
    
    return 0;
}