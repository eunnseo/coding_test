#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int my_main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    stringstream ss1(s1);
    stringstream ss2(s2);

    int n, x;
    ss1 >> n >> x;

    vector<int> a;
    string elem;
    while (getline(ss2, elem, ' '))
    {
        a.push_back(stoi(elem));
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < x)
        {
            cout << a[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, t;
    cin >> n >> x;
    while (n--)
    {
        cin >> t;
        if (t < x) cout << t << ' ';
    }
}