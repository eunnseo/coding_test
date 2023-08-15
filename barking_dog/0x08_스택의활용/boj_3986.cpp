#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int res = 0;
    int n;
    cin >> n;

    while (n--)
    {
        stack<char> S;
        string line;
        cin >> line;

        for (int i = 0; i < line.size(); i++)
        {
            if (S.empty() || line[i] != S.top())
            {
                S.push(line[i]);
            }
            else if (line[i] == S.top())
            {
                S.pop();
            }
        }
        if (S.empty()) res++;
    }
    cout << res << "\n";

    return 0;
}