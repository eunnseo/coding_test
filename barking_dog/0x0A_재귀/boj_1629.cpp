#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull func1(ull a, ull b, ull c)
{
    if (b == 0) return 1;
    if (b == 1) return a % c;
    
    if (b % 2 == 0) return func1(a, b/2, c) % c * func1(a, b/2, c) % c;
	return func1(a, b/2, c) % c * func1(a, b/2, c) % c * a % c;
}

ull func2(ull a, ull b, ull c)
{
    if (b == 0) return 1;
    if (b == 1) return a % c;
    
    ull val = func2(a, b/2, c) % c;
    if (b % 2 == 0) return val * val % c;
    return val * val % c * a % c;
}

int main()
{
    ull a, b, c;
    cin >> a >> b >> c;

    cout << func2(a, b, c) << endl;

    return 0;
}

// Âü°í
// https://velog.io/@junttang/BOJ-1629-%EA%B3%B1%EC%85%88-%ED%95%B4%EA%B2%B0-%EC%A0%84%EB%9E%B5-C