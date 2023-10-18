#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nA, nB;
int A[500002];
int B[500002];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> nA >> nB;
    for (int i = 0; i < nA; i++)
        cin >> A[i];
    for (int i = 0; i < nB; i++)
        cin >> B[i];

    int res = 0;
    sort(B, B + nB);

    for (int i = 0; i < nA; i++)
    {
        if (!binary_search(B, B + nB, A[i]))
        {
            res++;
            v.push_back(A[i]);
        }
    }

    sort(v.begin(), v.end());

    cout << res << "\n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}