#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int res = 0;
    for (int i = 0; i < 5; i++)
    {
        string st, en;
        cin >> st >> en;
        int st_h = stoi(st.substr(0, 2));
        int st_m = stoi(st.substr(3, 5));
        int en_h = stoi(en.substr(0, 2));
        int en_m = stoi(en.substr(3, 5));
        res += ((en_h - st_h) * 60 + (en_m - st_m));
    }
    cout << res;

    return 0;
}