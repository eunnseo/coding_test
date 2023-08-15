#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string line;
        stack<char> S;

        getline(cin, line);

        if (line == ".") break;

        bool ok = true;
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '(')
            {
                S.push('(');
            }
            else if (line[i] == ')')
            {
                if (!S.empty() && S.top() == '(') S.pop();
                else ok = false;
            }
            else if (line[i] == '[')
            {
                S.push('[');
            }
            else if (line[i] == ']')
            {
                if (!S.empty() && S.top() == '[') S.pop();
                else ok = false;
            }
            else if (line[i] == '.')
            {
                break;
            }

            if (!ok) break;
        }

        if (ok && S.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}