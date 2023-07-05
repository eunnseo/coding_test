#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> n_list;
    list<int> result;
    for (int i = 1; i <= n; i++)
    {
        n_list.push_back(i);
    }

    list<int>::iterator n_it = n_list.begin();
    while (!n_list.empty())
    {
        for (int i = 0; i < (k - 1); i++)
        {
            n_it++;
            if (n_it == n_list.end())
            {
                n_it = n_list.begin();
            }
        }
        result.push_back(*n_it);

        list<int>::iterator erase_it = n_it;
        n_it++;
        if (n_it == n_list.end())
        {
            n_it = n_list.begin();
        }
        n_list.erase(erase_it);
    
        // cout << "n_list = (";
        // for (auto iter = n_list.begin(); iter != n_list.end(); iter++)
        // {
        //     cout << *iter << ", ";
        // }
        // cout << ")\n";
        // cout << "<";
        // for (auto iter = result.begin(); iter != result.end(); iter++)
        // {
        //     cout << *iter << ", ";
        // }
        // cout << ">\n";
    }

    list<int>::iterator iter = result.begin();
    cout << "<" << *iter;
    iter++;
    for (; iter != result.end(); iter++)
    {
        cout << ", " << *iter;
    }
    cout << ">\n";

    return 0;
}