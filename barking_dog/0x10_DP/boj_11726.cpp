#include <iostream>
using namespace std;

int n;
int D[1002];

void dp()
{
    D[1] = 1;
    D[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        D[i] = (D[i-1] + D[i-2]) % 10007;
    }

    cout << D[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp();

    return 0;
}