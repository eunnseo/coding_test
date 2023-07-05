#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;
    vector<char> result;

    while (n--)
    {
        int input;
        cin >> input;

        if (s.top() == input)
        {
            s.pop();
            result.push_back('-');
        }
        else if (s.top() < input)
        {
            while (s.top() <= input)
            {
                s.push(s.top() + 1);
                result.push_back('+');
            }
            s.pop();
            result.push_back('-');
        }
        else
        {
            while (s.top() >= input)
            {
                s.pop();
                result.push_back('-');
            }
        }
    }

    return 0;
}