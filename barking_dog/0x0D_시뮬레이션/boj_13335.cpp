#include <iostream>
#include <deque>
using namespace std;

#define IDX first
#define TIME second

int n, bridge_len, max_weight;
int truck_w[1002]; // weight
deque<pair<int, int>> bridge; // truck_idx, time

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> bridge_len >> max_weight;
    for (int i = 0; i < n; i++)
        cin >> truck_w[i];

    bridge.push_back({0, 0});
    int res = 0;

    while (!bridge.empty())
    {
        res++;

        for (int i = 0; i < bridge.size(); i++)
        {
            bridge[i].TIME++;
        }

        while (!bridge.empty() && bridge.front().TIME >= bridge_len)
        {
            bridge.pop_front();
        }

        if (bridge.back().IDX == n-1) continue;

        pair<int, int> next_truck = {bridge.back().IDX + 1, 0};

        int bridge_w = 0;
        for (int i = 0; i < bridge.size(); i++)
            bridge_w += truck_w[bridge[i].IDX];
        
        if (bridge_w + truck_w[next_truck.IDX] > max_weight) continue;
        if (bridge.size() == bridge_len) continue;

        bridge.push_back(next_truck);
    }
    cout << res+1 << endl;

    return 0;
}