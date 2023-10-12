#include <iostream>
#include <cstring>
using namespace std;

string input;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> input;
    
    int res = 0;
    bool isSum = true;
    int i = 0;
    while (i < input.size())
    {
        if (input[i] == '-')
        {
            isSum = false;
            i++;
        }
        else if (input[i] == '+')
        {
            i++;
        }
        else
        {
            int num = 0;
            while (isdigit(input[i]))
            {
                num = ((input[i] - '0') + (num * 10));
                i++;
            }
            if (isSum) res += num;
            else res -= num;
        }
    }
    cout << res;

    return 0;
}