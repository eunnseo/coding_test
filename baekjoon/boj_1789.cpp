#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll s;
    cin >> s;

    ll i = 1;
    ll tmp_sum = 1;

    while (1)
    {
        if (s < (tmp_sum + i + 1)) break;
        i++;
        tmp_sum += i;
    }
    cout << i;

    return 0;
}