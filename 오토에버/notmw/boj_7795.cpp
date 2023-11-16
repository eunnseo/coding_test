#include <iostream>
#include <algorithm>
using namespace std;

int A[20005];
int B[20005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < m; i++) cin >> B[i];

        sort(A, A + n);
        sort(B, B + m);

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += lower_bound(B, B + m, A[i]) - B;
        }
        cout << res << "\n";
    }

    return 0;
}