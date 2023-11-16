#include <iostream>
using namespace std;

int n, s, r;
int arr[15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> r;
    for (int i = 0; i < n; i++)
        arr[i] = 1;

    for (int i = 0; i < s; i++)
    {
        int team;
        cin >> team;
        arr[team-1] = 0;
    }
    for (int i = 0; i < r; i++)
    {
        int team;
        cin >> team;
        arr[team-1]++;
    }

    if (arr[0] == 2 && arr[1] == 0)
    {
        arr[0] = 1;
        arr[1] = 1;
    }
    if (arr[n-1] == 2 && arr[n-2] == 0)
    {
        arr[n-1] = 1;
        arr[n-2] = 1;
    }

    for (int i = 1; i < n-1; i++)
    {
        if (arr[i] == 2)
        {
            if (arr[i-1] == 0 && arr[i+1] > 0)
            {
                arr[i] = 1;
                arr[i-1] = 1;
            }
            else if (arr[i-1] > 0 && arr[i+1] == 0)
            {
                arr[i] = 1;
                arr[i+1] = 1;
            }
            else
            {
                continue;
            }
        }
    }
    for (int i = 1; i < n-1; i++)
    {
        if (arr[i] == 2)
        {
            if (arr[i-1] == 0)
            {
                arr[i] = 1;
                arr[i-1] = 1;
            }
            else if (arr[i+1] == 0)
            {
                arr[i] = 1;
                arr[i+1] = 1;
            }
            else
            {
                continue;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            res++;
    }
    cout << res;

    return 0;
}