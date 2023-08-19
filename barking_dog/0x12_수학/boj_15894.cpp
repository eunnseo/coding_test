#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long n;
    cin >> n;

    unsigned long long res = n << 2;
    cout << res;

    return 0;
}