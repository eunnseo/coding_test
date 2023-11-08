#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    arr.push_back(s);
    for (int i = 1; i < s.size(); i++)
        arr.push_back(s.substr(i, s.size() - 1));

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "\n";

    return 0;
}