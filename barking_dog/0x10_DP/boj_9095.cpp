#include <iostream>
using namespace std;

int arr[13];

void dp()
{
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i <= 11; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << arr[n] << "\n";
    }

    return 0;
}