#include <iostream>
#include <vector>
using namespace std;

int n;
int board[100002];
int done[100002];
int vis[100002];
vector<int> team;

int find(int num)
{
    for (int i = 0; i < team.size(); i++)
    {
        if (num == team[i]) return i;
    }
    return -1;
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << board[i] << "\t";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << done[i] << "\t";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << vis[i] << "\t";
    }
    cout << endl;
    cout << "team > ";
    for (int i = 0; i < team.size(); i++)
    {
        cout << team[i] << " ";
    }
    cout << endl;
}

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

        // cout << "----------- start -----------" << endl;

        for (int i = 1; i <= n; i++)
        {
            if (done[i] == 1 || vis[i] == 1) continue;

            // cout << "i = " << i << endl;

            int curr = i;
            team.clear();
            team.push_back(curr);

            // cout << "======== 1 ========" << endl;
            // print();
            // cout << "===================" << endl;

            while (1)
            {
                vis[curr] = 1;

                int next = board[curr];
                int idx = find(next);

                // cout << "\t next = " << next << endl;
                // cout << "\t idx = " << idx << endl;

                if (idx == -1)
                {
                    team.push_back(next);
                    curr = next;
                }
                else
                {
                    for (int j = idx; j < team.size(); j++)
                        done[team[j]] = 1;
                    break;
                }
                // print();
            }

            // cout << "======== 2 ========" << endl;
            // print();
            // cout << "===================" << endl;
            // cout << endl;
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
            if (done[i] == 0) res++;
        cout << res << "\n";
    }

    return 0;
}