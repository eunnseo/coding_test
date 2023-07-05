#include <iostream>
#include <cstring>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    char str[100001];
    cin >> str;

    list<char> str_list;
    list<char>::iterator cursor = str_list.end();
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        str_list.push_back(str[i]);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'L')
        {
            if (cursor == str_list.begin()) continue;
            cursor--;
        }
        else if (cmd == 'D')
        {
            if (cursor == str_list.end()) continue;
            cursor++;
        }
        else if (cmd == 'B')
        {
            if (cursor == str_list.begin()) continue;
            list<char>::iterator erase_cursor = cursor;
            erase_cursor--;
            str_list.erase(erase_cursor);
        }
        else if (cmd == 'P')
        {
            char c;
            cin >> c;
            str_list.insert(cursor, c);
        }
    }

    for (auto it = str_list.begin(); it != str_list.end(); it++)
    {
        cout << *it;
    }

    return 0;
}