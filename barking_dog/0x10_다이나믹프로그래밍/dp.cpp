#include <iostream>
using namespace std;

int fibo(int n)
{
    int f[20];
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int n = 0; n <= 7; n++)
        cout << fibo(n) << endl;

    return 0;
}