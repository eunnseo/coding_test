#include <iostream>
using namespace std;

int n;
int D[1000002];
int D2[1000002];

void dp()
{
    D[1] = 0;
    
    for (int i = 2; i <= n; i++)
    {
        if ((i % 3 == 0) && (i % 2 == 0))
        {
            if (D[i/3] < D[i/2])
            {
                if (D[i/3] < D[i-1])
                {
                    D[i] = D[i/3] + 1;
                    D2[i] = i/3;
                }
                else
                {
                    D[i] = D[i-1] + 1;
                    D2[i] = i-1;
                }
            }
            else
            {
                if (D[i/2] < D[i-1])
                {
                    D[i] = D[i/2] + 1;
                    D2[i] = i/2;
                }
                else
                {
                    D[i] = D[i-1] + 1;
                    D2[i] = i-1;
                }
            }
        }
        else if (i % 3 == 0)
        {
            if (D[i/3] < D[i-1])
            {
                D[i] = D[i/3] + 1;
                D2[i] = i/3;
            }
            else
            {
                D[i] = D[i-1] + 1;
                D2[i] = i-1;
            }
        }
        else if (i % 2 == 0)
        {
            if (D[i/2] < D[i-1])
            {
                D[i] = D[i/2] + 1;
                D2[i] = i/2;
            }
            else
            {
                D[i] = D[i-1] + 1;
                D2[i] = i-1;
            }
        }
        else
        {
            D[i] = D[i-1] + 1;
            D2[i] = i-1;
        }
    }

    cout << D[n] << "\n";
    while (n >= 1)
    {
        cout << n << " ";
        n = D2[n];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp();

    return 0;
}