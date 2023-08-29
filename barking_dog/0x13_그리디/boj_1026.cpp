#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
unsigned long long S = 0;
vector<unsigned long long> A;
vector<unsigned long long> B;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        B.push_back(tmp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    for (int i = 0; i < n; i++)
    {
        S += (A[i] * B[i]);
    }
    cout << S;

    return 0;
}