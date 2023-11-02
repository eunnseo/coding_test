#include <iostream>
using namespace std;

int gear[10];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 8; i++) cin >> gear[i];

    if (gear[0] == 1)
    {
        bool ok = true;
        for (int i = 1; i < 8; i++)
        {
            if (gear[i] == i+1)
            {
                continue;
            }
            else
            {
                cout << "mixed\n";
                ok = false;
                break;
            }
        }
        if (ok) cout << "ascending\n";
    }
    else if (gear[0] == 8)
    {
        bool ok = true;
        for (int i = 1; i < 8; i++)
        {
            if (gear[i] == 8-i)
            {
                continue;
            }
            else
            {
                cout << "mixed\n";
                ok = false;
                break;
            }
        }
        if (ok) cout << "descending\n";
    }
    else
    {
        cout << "mixed\n";
    }

    return 0;
}