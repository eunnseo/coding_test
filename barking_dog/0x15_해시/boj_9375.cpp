#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> fashion;
vector<int> fashion_arr;
int arr[30];
int res = 0;

void dfs(int idx, int num)
{
    if (idx == num)
    {
        for (int i = 0; i < num; i++)
            cout << arr[fashion_arr[i]] << " ";
            // cout << arr[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < num; i++)
    {
        arr[idx] = i;
        dfs(idx+1, num);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            string name, kind;
            cin >> name >> kind;
            if (fashion.find(kind) == fashion.end())
            {
                fashion[kind] = 1;
            }
            else
            {
                fashion[kind]++;
            }
        }
        for (auto iter = fashion.begin(); iter != fashion.end(); iter++)
            fashion_arr.push_back(iter->second);

        cout << "fashion_arr = ";
        for (int i = 0; i < fashion_arr.size(); i++)
        {
            cout << fashion_arr[i] << " ";
        }
        cout << endl;

        dfs(0, 2);

        // for (int i = 0; i < fashion_arr.size(); i++)
        // {
        //     dfs(0, i);
        // }
    }

    return 0;
}