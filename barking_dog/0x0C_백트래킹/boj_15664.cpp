#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> input;
int isused[10];
int arr[10];

void func(int idx, int start)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = start; i < input.size(); i++)
    {
        if (!isused[i] && input[i] != tmp)
        {
            isused[i] = true;
            arr[idx] = input[i];
            tmp = arr[idx];
            func(idx + 1, i);
            isused[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    sort(input.begin(), input.end());

    func(0, 0);

    return 0;
}