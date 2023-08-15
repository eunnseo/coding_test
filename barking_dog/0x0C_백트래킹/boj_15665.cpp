#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> input;
int arr[10];

void func(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < input.size(); i++)
    {
        arr[idx] = input[i];
        func(idx+1);
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

        bool exist = false;
        for (int j = 0; j < input.size(); j++)
        {
            if (input[j] == tmp)
            {
                exist = true;
                break;
            }
        }
        if (!exist) input.push_back(tmp);
    }

    sort(input.begin(), input.end());

    func(0);
    
    return 0;
}