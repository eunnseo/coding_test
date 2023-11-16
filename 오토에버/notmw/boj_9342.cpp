#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string input;
        cin >> input;

        int idx = 0;

        // 1
        if (input[0] == 'B' || input[0] == 'C' || input[0] == 'D' || input[0] == 'E' || input[0] == 'F')
        {
            idx++;
        }
        else if (input[0] == 'A')
        {
            idx = 0;
        }
        else
        {
            cout << "Good\n";
            continue;
        }

        // 2
        if (input[idx] != 'A')
        {
            cout << "Good\n";
            continue;
        }
        while (input[idx] == 'A')
        {
            idx++;
        }

        // 3
        if (input[idx] != 'F')
        {
            cout << "Good\n";
            continue;
        }
        while (input[idx] == 'F')
        {
            idx++;
        }

        // 4
        if (input[idx] != 'C')
        {
            cout << "Good\n";
            continue;
        }
        while (input[idx] == 'C')
        {
            idx++;
        }

        // 5
        if (idx < input.size() - 1)
        {
            cout << "Good\n";
            continue;
        }
        if (idx == input.size() - 1)
        {
            if (input[idx] != 'A' && input[idx] != 'B' && input[idx] != 'C' && input[idx] != 'D' && input[idx] != 'E' && input[idx] != 'F')
            {
                cout << "Good\n";
                continue;
            }
        }
        
        cout << "Infected!\n";
    }

    return 0;
}