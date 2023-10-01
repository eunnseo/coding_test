#include <iostream>
#include <algorithm>
using namespace std;

int num;
int stairs[302];
int D[302][2];

void dp()
{
    D[1][1] = stairs[1];
    D[1][2] = 0;
    D[2][1] = stairs[2];
    D[2][2] = stairs[1] + stairs[2];

    for (int i = 3; i <= num; i++)
    {
        D[i][1] = max(D[i-2][1], D[i-2][2]) + stairs[i];
        D[i][2] = D[i-1][1] + stairs[i];
    }

    cout << max(D[num][1], D[num][2]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;
    for (int i = 1; i <= num; i++)
        cin >> stairs[i];

    dp();

    return 0;
}