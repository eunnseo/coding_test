#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1002];
int two[1000002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            two[i*n+j] = arr[i] + arr[j];
        }
    }

    int n_two = n * n;
    sort(two, two + n_two);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int target = arr[i] - arr[j];
            if (binary_search(two, two + n_two, target))
            {
                if (res < arr[i]) res = arr[i];
            }
        }
    }

    cout << res;

    return 0;
}