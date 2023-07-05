#include <iostream>
#include <cstring>
#include <list>
using namespace std;

char pw[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string pw;
        cin >> pw;

        list<char> pw_list;
        list<char>::iterator cursor = pw_list.begin();

        int l = pw.size();
        for (int i = 0; i < l; i++)
        {
            if (pw[i] == '<')
            {
                if (pw_list.empty() || cursor == pw_list.begin()) continue;
                cursor--;
            }
            else if (pw[i] == '>')
            {
                if (pw_list.empty() || cursor == pw_list.end()) continue;
                cursor++;
            }
            else if (pw[i] == '-')
            {
                if (pw_list.empty() || cursor == pw_list.begin()) continue;
                list<char>::iterator erase_it = cursor;
                erase_it--;
                pw_list.erase(erase_it);
            }
            else
            {
                pw_list.insert(cursor, pw[i]);
            }
        }

        for (auto iter = pw_list.begin(); iter != pw_list.end(); iter++)
        {
            cout << *iter;
        }
        cout << "\n";
    }

    return 0;
}