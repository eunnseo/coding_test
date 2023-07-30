#include <iostream>
using namespace std;

int func(int n, int r, int c)
{
    if (n == 0) return 0;
    int half = 1 << (n-1);
    if (r < half && c < half) return func(n-1, r, c);
    else if (r < half && c >= n) return func(n-1, r, c-half) + half * half;
    else if (r >= n && c < half) return func(n-1, r-half, c) + half * half * 2;
    else return func(n-1, r-half, c-half) + half * half * 3;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);

    return 0;
}