#include <iostream>
using namespace std;

int n, m, num;
int D[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> num;
    D[1] = num;
    for (int i = 2; i <= n; i++)
    {
        cin >> num;
        D[i] = num + D[i-1];
    }

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cout << D[j] - D[i-1] << "\n";
    }

    return 0;
}