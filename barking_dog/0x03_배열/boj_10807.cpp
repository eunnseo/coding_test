#include <iostream>
using namespace std;

int n, v;
int arr[102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> v;

    int res = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == v) res++;

    cout << res;

    return 0;
}