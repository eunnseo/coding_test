#include <bits/stdc++.h>
using namespace std;

void unordered_set_example()
{
    unordered_set<int> s;
    s.insert(-10);
    s.insert(100);
    s.insert(15);
    s.insert(-10);

    cout << s.size() << endl;
    for (auto e : s) cout << e << ' ';
    cout << endl;
    cout << endl;

    cout << s.erase(-10) << '\n';

    cout << s.size() << endl;
    for (auto e : s) cout << e << ' ';
    cout << endl;
    cout << endl;

    cout << s.erase(100) << '\n';
    cout << s.erase(20) << '\n';

    cout << s.size() << endl;
    for (auto e : s) cout << e << ' ';
    cout << endl;
    cout << endl;

    if (s.find(15) != s.end()) cout << "15 in s" << endl;
    else cout << "15 not in s" << endl;

    cout << s.size() << endl;
    cout << s.count(50) << endl;
}

void unordered_map_example()
{
    unordered_map<string, int> m;

    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165;

    cout << m.size() << endl;

    m["hi"] = -7;

    if (m.find("hi") != m.end()) cout << "hi in m" << endl;
    else cout << "hi not in m" << endl;

    for (auto e : m)
        cout << e.first << " " << e.second << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // unordered_set_example();
    unordered_map_example();

    return 0;
}