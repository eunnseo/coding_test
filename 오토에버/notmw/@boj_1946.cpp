#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
pair<int, int> arr[100005];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

        sort(arr, arr+n, cmp);

        int res = 1;
        int rank = arr[0].second;
        for (int i = 1; i < n; i++)
        {
            if (arr[i].second < rank)
                res++;
            rank = min(rank, arr[i].second); // O(NlgN) -> O(N)
        }
        cout << res << "\n";
    }

    return 0;
}