#include <iostream>
using namespace std;

int n, s;
int arr[22];
int cnt = 0;

void func(int idx, int total)
{
    if (idx == n)
    {
        if (total == s) cnt++;
        return;
    }
    func(idx+1, total);
    func(idx+1, total+arr[idx]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    func(0, 0);
    if (s == 0) cnt--;
    cout << cnt;

    return 0;
}