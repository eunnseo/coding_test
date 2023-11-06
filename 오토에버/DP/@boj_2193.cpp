#include <iostream>
using namespace std;

using ll = long long;

int n;
ll D[95];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    D[1] = 1;
    D[2] = 1;
    for (int i = 3; i <= n; i++)
        D[i] = D[i-1] + D[i-2];

    cout << D[n];

    return 0;
}

// ref: https://guiyum.tistory.com/15