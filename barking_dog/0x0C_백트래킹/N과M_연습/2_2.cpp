#include <iostream>
using namespace std;

int n, m;
int arr[10];

void bfs(int idx, int st)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = st; i <= n; i++)
    {
        arr[idx] = i;
        bfs(idx + 1, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    bfs(0, 1);

    return 0;
}