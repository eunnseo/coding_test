#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    stack<int> s;
    
    while (k--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            s.pop();
        }
        else
        {
            s.push(n);
        }

        for (int i = 0; i < s.size(); i++)
        {
        }
    }

    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum << "\n";

    return 0;
}