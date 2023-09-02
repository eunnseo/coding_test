#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}
unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        unsigned long long a, b;
        cin >> a >> b;
        cout << lcm(a, b) << "\n";
    }

    return 0;
}