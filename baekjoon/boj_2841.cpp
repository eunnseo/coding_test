#include <bits/stdc++.h>
using namespace std;

int n, p;
int res = 0;
vector<stack<int>> guitar(6);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p;
    while (n--)
    {
        int line, pret;
        cin >> line >> pret;
        line -= 1;

        if (guitar[line].empty() || guitar[line].top() < pret)
        {
            guitar[line].push(pret);
            res++;
        }
        else if (guitar[line].top() > pret)
        {
            while (1)
            {
                if (guitar[line].empty() || guitar[line].top() <= pret) break;

                guitar[line].pop();
                res++;
            }
            if (guitar[line].empty() || guitar[line].top() < pret)
            {
                guitar[line].push(pret);
                res++;
            }
        }
        else
        {
            /* do nothing */
        }
    }

    cout << res;

    return 0;
}