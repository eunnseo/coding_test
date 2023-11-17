#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string board;
    cin >> board;

    string res = string();

    int x_cnt = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == 'X')
        {
            x_cnt++;
            if (x_cnt == 4)
            {
                res += "AAAA";
                x_cnt = 0;
            }
        }
        else if (board[i] == '.')
        {
            if (x_cnt == 4)
            {
                res += "AAAA";
                x_cnt = 0;
            }
            else if (x_cnt == 2)
            {
                res += "BB";
                x_cnt = 0;
            }
            else if (x_cnt == 1 || x_cnt == 3)
            {
                cout << "-1";
                return 0;
            }
            res += '.';
        }
    }
    if (x_cnt == 4)
    {
        res += "AAAA";
    }
    else if (x_cnt == 2)
    {
        res += "BB";
    }
    else if (x_cnt == 1 || x_cnt == 3)
    {
        cout << "-1";
        return 0;
    }
    cout << res;
    return 0;
}