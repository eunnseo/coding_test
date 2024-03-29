#include <iostream>
using namespace std;

int D[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    D[2] = 1;
    D[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        D[i] = D[i-1] + 1;
        if (i % 3 == 0)
            D[i] = min(D[i/3] + 1, D[i]);
        if (i % 2 == 0)
            D[i] = min(D[i/2] + 1, D[i]);
    }
    cout << D[n];
    return 0;
}