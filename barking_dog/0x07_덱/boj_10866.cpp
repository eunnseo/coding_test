#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> DQ;
    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd.compare("push_front") == 0)
        {
            int x;
            cin >> x;
            DQ.push_front(x);
        }
        else if (cmd.compare("push_back") == 0)
        {
            int x;
            cin >> x;
            DQ.push_back(x);
        }
        else if (cmd.compare("pop_front") == 0)
        {
            if (DQ.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }
        else if (cmd.compare("pop_back") == 0)
        {
            if (DQ.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        else if (cmd.compare("size") == 0)
        {
            cout << DQ.size() << "\n";
        }
        else if (cmd.compare("empty") == 0)
        {
            if (DQ.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (cmd.compare("front") == 0)
        {
            if (DQ.empty())
                cout << "-1\n";
            else
                cout << DQ.front() << "\n";
        }
        else if (cmd.compare("back") == 0)
        {
            if (DQ.empty())
                cout << "-1\n";
            else
                cout << DQ.back() << "\n";
        }
    }

    return 0;
}