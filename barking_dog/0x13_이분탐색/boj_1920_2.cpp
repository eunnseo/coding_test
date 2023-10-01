#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100002];

int my_binary_search(int num)
{
    int st = 0;
    int mid = 0;
    int en = n-1;

    while (st <= en)
    {
        mid = (st + en) / 2;

        if (arr[mid] < num)
        {
            st = mid + 1;
        }
        else if (arr[mid] == num)
        {
            return mid;
        }
        else
        {
            en = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    cin >> m;
    while (m--)
    {
        int num;
        cin >> num;

        if (my_binary_search(num) != -1)
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}