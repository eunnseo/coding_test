#include <iostream>
using namespace std;

int n;
int D[1000005];
int D_prev[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    D[2] = 1;
    D_prev[2] = 1;
    D[3] = 1;
    D_prev[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        D[i] = D[i-1] + 1;
        D_prev[i] = i-1;
        if (i % 2 == 0)
        {
            if (D[i/2] + 1 < D[i])
            {
                D[i] = D[i/2] + 1;
                D_prev[i] = i/2;
            }
        }
        if (i % 3 == 0)
        {
            if (D[i/3] + 1 < D[i])
            {
                D[i] = D[i/3] + 1;
                D_prev[i] = i/3;
            }
        }
    }
    
    cout << D[n] << "\n";

    int idx = n;
    while (1)
    {
        cout << idx << " ";
        idx = D_prev[idx];

        if (idx < 1) break;
    }

    return 0;
}