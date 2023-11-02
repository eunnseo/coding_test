#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a > b)
        cout << "A";
    else if (a == b)
        cout << "same";
    else
        cout << "B";

    return 0;
}