#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    int sq_n = sqrt(n);
    for (int i = 2; i <= sq_n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    if (m == 1) m++;
    for (int i = m; i <= n; i++)
    {
        if (isPrime(i)) cout << i << "\n";
    }

    return 0;
}