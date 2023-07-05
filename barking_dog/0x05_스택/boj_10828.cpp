#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> my_stack;

    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd.compare("push") == 0)
        {
            int x;
            cin >> x;
            my_stack.push(x);
        }
        else if (cmd.compare("pop") == 0)
        {
            if (my_stack.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << my_stack.top() << endl;
                my_stack.pop();
            }
        }
        else if (cmd.compare("size") == 0)
        {
            cout << my_stack.size() << endl;
        }
        else if (cmd.compare("empty") == 0)
        {
            if (my_stack.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (cmd.compare("top") == 0)
        {
            if (my_stack.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << my_stack.top() << endl;
            }
        }
    }

    return 0;
}