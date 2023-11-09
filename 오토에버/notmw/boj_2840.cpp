#include <iostream>
#include <vector>
using namespace std;

char arr[30];
bool isused[30];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    int idx = 0;
    while (k--)
    {
        int s;
        char c;
        cin >> s >> c;

        idx += s;
        idx %= n;

        if (isused[idx])
        {
            if (arr[idx] == c)
            {
                continue;
            }
            else
            {
                cout << "!";
                return 0;
            }
        }
        else
        {
            /////////////////// Hidden ///////////////////
            for (int i = 0; i < n; i++)
            {
                if (isused[i] && arr[i] == c)
                {
                    cout << "!";
                    return 0;
                }
            }
            /////////////////// Hidden ///////////////////
            isused[idx] = true;
            arr[idx] = c;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        int j = idx + i + 1;
        j %= n;
        if (isused[j])
            cout << arr[j];
        else
            cout << "?";
    }

    return 0;
}