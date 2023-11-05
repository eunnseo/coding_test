#include <iostream>
using namespace std;

int n;
int input[1005][3];
int D[1005][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> input[i][0] >> input[i][1] >> input[i][2];

    D[0][0] = input[0][0];
    D[0][1] = input[0][1];
    D[0][2] = input[0][2];

    for (int i = 1; i < n; i++)
    {
        D[i][0] = min(D[i-1][1], D[i-1][2]) + input[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + input[i][1];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + input[i][2];
    }

    int res = min(D[n-1][0], D[n-1][1]);
    res = min(res, D[n-1][2]);
    cout << res;

    return 0;
}