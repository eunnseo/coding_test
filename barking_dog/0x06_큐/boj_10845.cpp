#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> Q;
    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd.compare("push") == 0)
        {
            int x;
            cin >> x;
            Q.push(x);
        }
        else if (cmd.compare("pop") == 0)
        {
            if (!Q.empty())
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (cmd.compare("size") == 0)
        {
            cout << Q.size() << "\n";
        }
        else if (cmd.compare("empty") == 0)
        {
            if (Q.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (cmd.compare("front") == 0)
        {
            if (!Q.empty())
                cout << Q.front() << "\n";
            else
                cout << "-1\n";
        }
        else if (cmd.compare("back") == 0)
        {
            if (!Q.empty())
                cout << Q.back() << "\n";
            else
                cout << "-1\n";
        }
    }

    return 0;
}