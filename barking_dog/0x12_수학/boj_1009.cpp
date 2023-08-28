#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long a, b;
        cin >> a >> b;

        unsigned long long n = 1;
        while (b--)
        {
            n *= a;
            n %= 10;
        }
        if (n == 0) cout << 10 << "\n";
        else cout << n << "\n";
    }

    return 0;
}