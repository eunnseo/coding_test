#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < 100002; i++)
        dist[i] = -1;

    queue<int> Q;
    dist[N] = 0;
    Q.push(N);

    while (!Q.empty())
    {
        int X = Q.front();
        Q.pop();

        int neighbors[3] = {X - 1, X + 1, 2 * X};

        for (int i = 0; i < 3; i++)
        {
            int nx = neighbors[i];

            if (nx < 0 || nx > 100000) continue;
            if (dist[nx] != -1) continue;

            dist[nx] = dist[X] + 1;
            Q.push(nx);
        }
    }

    cout << dist[K] << "\n";

    return 0;
}