#include <iostream>
#include <vector>
using namespace std;

int n;
int board[100002];
int done[100002];
int vis[100002];
vector<int> team;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> board[i];
            done[i] = 0;
            vis[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            if (done[i] == 1 || vis[i] == 1) continue;
            team.clear();

            int curr = i;
            team.push_back(curr);
            vis[curr] = 1;

            while (1)
            {
                int next = board[curr];

                if (vis[next] == 0)
                {
                    team.push_back(next);
                    vis[next] = 1;
                    curr = next;
                }
                else
                {
                    int idx;
                    for (idx = 0; idx < team.size(); idx++)
                    {
                        if (team[idx] == next) break;
                    }
                    for (int j = idx; j < team.size(); j++)
                    {
                        done[team[j]] = 1;
                    }
                    break;
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
            if (done[i] == 0) res++;
        cout << res << "\n";
    }

    return 0;
}