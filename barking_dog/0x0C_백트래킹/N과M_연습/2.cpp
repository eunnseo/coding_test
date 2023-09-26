#include <iostream>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void func(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!isused[i])
        {
            if (idx > 0 && arr[idx-1] > i) continue;

            isused[i] = 1;
            arr[idx] = i;
            func(idx+1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);

    return 0;
}