#include <iostream>
using namespace std;

typedef long long ll;

ll s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;

    ll sum_n = 0;
    ll i = 0;
    while (sum_n <= s)
    {
        i++;
        sum_n += i;
    }
    cout << i-1;

    return 0;
}