#include <iostream>
using namespace std;

int fact(int a, int b)
{
    int res = 1;
    for (int i = a; i >= b; i--)
    {
        res *= i;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (k > n-k)
    {
        cout << fact(n, k+1) / fact(n-k, 2);
    }
    else
    {
        cout << fact(n, n-k+1) / fact(k, 2);
    }

    return 0;
}