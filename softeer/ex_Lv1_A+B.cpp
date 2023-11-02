#include <iostream>

using namespace std;

int t;

int main(int argc, char **argv)
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << "\n";
    }
    return 0;
}