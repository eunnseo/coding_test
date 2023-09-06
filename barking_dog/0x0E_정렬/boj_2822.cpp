#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr;
    vector<int> sorted_arr;
    for (int i = 0; i < 8; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        sorted_arr.push_back(tmp);
    }
    sort(sorted_arr.begin(), sorted_arr.end());

    int thres = sorted_arr[3];

    int res = 0;
    for (int i = 3; i < 8; i++)
    {
        res += sorted_arr[i];
    }

    cout << res << "\n";
    for (int i = 0; i < 8; i++)
    {
        if (thres <= arr[i])
            cout << i+1 << " ";
    }

    return 0;
}