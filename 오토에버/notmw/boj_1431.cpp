#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

int n;
string arr[55];

bool cmp(string a, string b)
{
    if (a.size() == b.size())
    {
        int sum_a = 0;
        int sum_b = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (isdigit(a[i]))
                sum_a += (a[i] - '0');
        }
        for (int i = 0; i < b.size(); i++)
        {
            if (isdigit(b[i]))
                sum_b += (b[i] - '0');
        }

        if (sum_a == sum_b)
        {
            if (isdigit(a[0]) && isalpha(b[0]))
            {
                return true;
            }
            else if (isalpha(a[0]) && isdigit(b[0]))
            {
                return false;
            }
            else
            {
                return a < b;
            }
        }
        return sum_a < sum_b;
    }
    return a.size() < b.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n, cmp);

    for (int i = 0; i < n; i++) cout << arr[i] << "\n";

    return 0;
}