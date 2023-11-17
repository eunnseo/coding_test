#include <iostream>
using namespace std;

string a, b;
int DP[1005][1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    for (int i = 0; i <= a.size(); i++)
        DP[0][i] = 0;
    for (int i = 0; i <= b.size(); i++)
        DP[i][0] = 0;

    for (int i = 1; i <= b.size(); i++)
    {
        for (int j = 1; j <= a.size(); j++)
        {
            if (a[j-1] == b[i-1])
            {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }

    // for (int i = 0; i <= b.size(); i++)
    // {
    //     for (int j = 0; j <= a.size(); j++)
    //     {
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << DP[b.size()][a.size()];

    return 0;
}

// ref: https://ongveloper.tistory.com/36