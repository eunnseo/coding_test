#include <iostream>
using namespace std;

int t, n;
int today, tomorrow;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;

        long long money = 0;
        int cnt = 0;

        cin >> tomorrow;

        for (int i = 0; i < n-1; i++)
        {
            today = tomorrow;
            cin >> tomorrow;

            if (today <= tomorrow)
            {
                // 1. buy
                money -= today;
                cnt++;
            }
            else
            {
                // 2. sell
                money += (today * cnt);
                cnt = 0;
            }
        }
        // last day (sell)
        money += (tomorrow * cnt);
        cout << money << "\n";
    }
    
    return 0;
}

// 반례
/*
1
4
1 2 1 100
    
# Output
100
    
# Answer
296
*/