#include <iostream>
#include <vector>
using namespace std;

int result[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> stack;
    vector<int> stack_idx;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        while (!stack.empty() && (input > stack.back()))
        {
            stack.pop_back();
            stack_idx.pop_back();
        }

        if (stack.empty())
            result[i] = 0;
        else
            result[i] = stack_idx.back();

        stack.push_back(input);
        stack_idx.push_back(i + 1);
    
        // cout << "stack: \n";
        // for (int j = 0; j < stack.size(); j++)
        // {
        //     cout << stack[j] << " ";
        // }
        // cout << endl;
        // cout << "stack_idx: \n";
        // for (int j = 0; j < stack_idx.size(); j++)
        // {
        //     cout << stack_idx[j] << " ";
        // }
        // cout << endl;
        // cout << "result: \n";
        // for (int j = 0; j < n; j++)
        // {
        //     cout << result[j] << " ";
        // }
        // cout << endl;
        // cout << endl;
    }
    for (int j = 0; j < n; j++)
    {
        cout << result[j] << " ";
    }
    cout << "\n";

/*
    int n;
    cin >> n;

    vector<int> stack;

    for (int i = 0; i < n; i++)
    {
        int top;
        cin >> top;
        stack.push_back(top);
    }

    while (!stack.empty())
    {
        int send_top_height = stack.back();
        int send_top_idx = stack.size() - 1;
        stack.pop_back();

        int start_idx = stack.size() - 1;
        for (int i = start_idx; i >= 0; --i)
        {
            if (send_top_height < stack[i])
            {
                result[send_top_idx] = i + 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
*/

    return 0;
}