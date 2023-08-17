#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int prime = 2;
    while (n > 1)
    {
        if (n % prime == 0)
        {
            cout << prime << "\n";
            n /= prime;
        }
        else
        {
            prime++;
        }
    }

    return 0;
}