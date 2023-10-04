#include <bits/stdc++.h>
using namespace std;

int n, m;
int cards[500002];

int lower_idx(int target, int len)
{
    int st = 0;
    int en = len;

    while (st < en)
    {
        int mid = (st + en) / 2;
        if (cards[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len)
{
    int st = 0;
    int en = len;

    while (st < en)
    {
        int mid = (st + en) / 2;
        if (cards[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cards[i];

    sort(cards, cards + n);

    cin >> m;
    while (m--)
    {
        int target;
        cin >> target;
        cout << upper_idx(target, n) - lower_idx(target, n) << " ";
    }

    return 0;
}