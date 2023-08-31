#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> balloon;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        balloon.push_back(tmp);
    }

    int idx = 0;
    int num = balloon[idx];
    balloon[idx] = 0;
    cout << idx + 1 << " ";

    for (int i = 0; i < n-1; i++)
    {
        if (num > 0)
        {
            while (num > 0)
            {
                idx++;
                if (idx == balloon.size()) idx = 0;
                if (balloon[idx] != 0) num--;
            }
        }
        else
        {
            while (num < 0)
            {
                idx--;
                if (idx < 0) idx = balloon.size() - 1;
                if (balloon[idx] != 0) num++;
            }
        }

        num = balloon[idx];
        balloon[idx] = 0;

        cout << idx + 1 << " ";
    }

    return 0;
}