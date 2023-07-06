#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> Q;

    for (int i = 0; i < n; i++)
    {
        Q.push(i+1);
    }
    while (Q.size() > 1)
    {
        Q.pop();
        int front = Q.front();
        Q.push(front);
        Q.pop();
    }

    cout << Q.front() << "\n";

    return 0;
}