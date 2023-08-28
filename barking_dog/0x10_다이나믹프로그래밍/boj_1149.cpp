#include <iostream>
#include <algorithm>
using namespace std;

int n;
int input[1002][3];
int D[1002][3];

void dp()
{
    D[1][0] = input[1][0];
    D[1][1] = input[1][1];
    D[1][2] = input[1][2];

    for (int i = 2; i <= n; i++)
    {
        D[i][0] = min(D[i-1][1], D[i-1][2]) + input[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + input[i][1];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + input[i][2];
    }

    int res = min(D[n][0], D[n][1]);
    res = min(res, D[n][2]);
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i][0] >> input[i][1] >> input[i][2];

    dp();

    return 0;
}