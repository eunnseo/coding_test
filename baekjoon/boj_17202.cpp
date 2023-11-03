#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    
    int arr[20];
    for (int i = 0; i < 8; i ++)
    {
        int idx = i * 2;
        arr[idx] = a[i] - '0';
        arr[idx+1] = b[i] - '0';
    }

    for (int i = 15; i >= 2; i--)
    {
        for (int j = 0; j < i; j++)
        {
            arr[j] = arr[j] + arr[j+1];
        }
    }

    cout << arr[0] % 10 << arr[1] % 10;

    return 0;
}