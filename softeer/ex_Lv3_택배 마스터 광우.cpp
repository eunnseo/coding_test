#include <iostream>

using namespace std;

int n, m, k;
int input[12];
int arr[12];
bool isused[12];
int res = 0x7fffffff;

void dfs(int idx)
{
    if (idx == n)
    {
        int all_weight = 0;
        int idx = 0;
        for (int i = 0; i < k; i++)
        {
            int weight = 0;
            while (1)
            {
                if ((weight + input[arr[idx]]) > m)
                    break;

                weight += input[arr[idx]];
                idx++;
                if (idx == n)
                    idx = 0;
            }
            all_weight += weight;
        }

        if (res > all_weight)
            res = all_weight;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            arr[idx] = i;
            dfs(idx + 1);
            isused[i] = false;
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> input[i];

    dfs(0);

    cout << res;

    return 0;
}