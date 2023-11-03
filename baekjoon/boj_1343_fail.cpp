#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string res = string();
    string input;
    cin >> input;

    int cntX = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'X')
        {
            cntX++;
            if (cntX == 4)
            {
                res += "AAAA";
                cntX = 0;
            }
        }
        else if (input[i] == '.')
        {
            if (cntX == 0)
            {
                res += ".";
            }
            else if (cntX % 2 == 0)
            {
                res += "BB.";
                cntX = 0;
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
    }

    if (cntX % 2 == 0)
    {
        res += "BB";
        cntX = 0;
    }
    else if (cntX == 0)
    {
    }
    else
    {
        cout << -1;
        return 0;
    }

    cout << res;
    return 0;
}
