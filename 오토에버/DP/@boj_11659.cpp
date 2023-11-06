#include <iostream>
using namespace std;

int n, m;
int input[100005];
int D[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> input[i];

    D[0] = 0;
    D[1] = input[1];
    for (int i = 2; i <= n; i++)
        D[i] = input[i] + D[i-1];

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cout << D[j] - D[i-1] << "\n";
    }

    return 0;
}