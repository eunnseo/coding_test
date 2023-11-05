#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[55];
int B[55];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    sort(A, A+n);
    sort(B, B+n, cmp);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (A[i] * B[i]);
    }
    cout << res;

    return 0;
}