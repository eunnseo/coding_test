#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[10];
int arr[10];
bool isused[10];

void bfs(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << num[arr[i]] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!isused[i] && tmp != num[i])
        {
            isused[i] = 1;
            arr[idx] = i;
            tmp = num[i];
            bfs(idx + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);

    bfs(0);

    return 0;
}