#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int five = n / 5;
    int two = 0;

    while (1)
    {
        if ((n - five * 5) % 2 != 0)
        {
            five--;
        }
        else
        {
            two = (n - five * 5) / 2;
            break;
        }
    }

    if (five < 0) cout << -1;
    else cout << five + two << endl;

    return 0;
}