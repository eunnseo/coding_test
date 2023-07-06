#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int top_num = 0;
    vector<int> stack;
    vector<char> result;

    bool ok = true;
    while (n--)
    {
        

        int input;
        cin >> input;

        if (input == top_num)
        {
            stack.pop_back();
            result.push_back('-');
        }
        else if (input > top_num)
        {
            while (input > top_num)
            {
                top_num++;
                stack.push_back(top_num);
                result.push_back('+');
            }
            stack.pop_back();
            result.push_back('-');
        }
        else
        {
            if (stack.empty() || stack.back() < input)
            {
                ok = false;
                break;
            }
            while ( (!stack.empty()) && (stack.back() >= input) )
            {
                stack.pop_back();
                result.push_back('-');
            }
        }
        
        // cout << "stack: ";
        // for (auto iter = stack.begin(); iter != stack.end(); iter++)
        // {
        //     cout << *iter << " ";
        // }
        // cout << endl;
        // cout << "result: ";
        // for (auto iter = result.begin(); iter != result.end(); iter++)
        // {
        //     cout << *iter << " ";
        // }
        // cout << endl;
        // cout << "top_num = " << top_num << endl;
    }

    if (ok)
    {
        for (auto iter = result.begin(); iter != result.end(); iter++)
        {
            cout << *iter << "\n";
        }
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}