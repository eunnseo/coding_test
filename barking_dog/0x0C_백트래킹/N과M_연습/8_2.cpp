#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int input[10];
int idx_arr[10];

void bfs(int idx, int st)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << input[idx_arr[i]] << " ";
        cout << "\n";
        return;
    }

    for (int i = st; i < n; i++)
    {
        idx_arr[idx] = i;
        bfs(idx + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input, input + n);

    bfs(0, 0);

    return 0;
}