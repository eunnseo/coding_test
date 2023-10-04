#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cards[500002];

int binary_search(int num)
{
    int st = 0;
    int en = n-1;
    int mid = 0;

    while (st <= en)
    {
        mid = (st + en) / 2;

        if (num > cards[mid])
        {
            st = mid + 1;
        }
        else if (num == cards[mid])
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
        cin >> cards[i];
    cin >> m;

    sort(cards, cards + n);

    while (m--)
    {
        int num;
        cin >> num;

        int idx = binary_search(num);
        if (idx == -1)
        {
            cout << "0 ";
            continue;
        }

        int res = 1;
        for (int i = idx + 1; i < n; i++)
        {
            if (cards[i] != num) break;
            res++;
        }
        for (int i = idx - 1; i >= 0; i--)
        {
            if (cards[i] != num) break;
            res++;
        }

        cout << res << " ";
    }

    return 0;
}