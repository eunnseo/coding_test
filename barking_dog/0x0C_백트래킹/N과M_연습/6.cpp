#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int input[10];
int arr[10];
int isused[10];

void func(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        if (!isused[i])
        {
            if (idx > 0 && arr[idx-1] > input[i]) continue;

            isused[i] = 1;
            arr[idx] = input[i];
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
    for (int i = 0; i < n; i++)
        cin >> input[i];
    
    sort(input, input+n);
    func(0);

    return 0;
}