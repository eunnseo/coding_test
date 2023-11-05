#include <iostream>
using namespace std;

int n;
int tri[505][505];
int D[505][505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }

    D[0][0] = tri[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                D[i][j] = D[i-1][j] + tri[i][j];
            else if (j == i)
                D[i][j] = D[i-1][j-1] + tri[i][j];
            else
                D[i][j] = max(D[i-1][j-1], D[i-1][j]) + tri[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (res < D[n-1][i]) res = D[n-1][i];
    }
    cout << res;

    return 0;
}