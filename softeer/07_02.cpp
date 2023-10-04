// 백트래킹

#include<iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

int n, m;
int map[6][6];
int visit[6][6];
vector<pair<int, int>> spot;
int res = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void input()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		spot.push_back({x-1, y-1});
	}
}

bool canGo(pair<int, int> target, int idx)
{
    for (int i = idx + 1; i < spot.size(); i++)
    {
        if (spot[i].X == target.X && spot[i].Y == target.Y)
            return false;
    }
    return true;
}

void go(pair<int, int> cur, int idx)
{
	if (idx == spot.size())
	{
        if (cur.X == spot.back().X && cur.Y == spot.back().Y)
		    res++;
		return;
	}

	pair<int, int> target = spot[idx];

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + cur.X;
		int ny = dy[i] + cur.Y;

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map[nx][ny] == 1 || visit[nx][ny] == 1) continue;
        if (!canGo({nx, ny}, idx)) continue;

		visit[nx][ny] = 1;

		if (nx == target.X && ny == target.Y)
		{
			go({nx, ny}, idx + 1);
		}
		else
		{
			go({nx, ny}, idx);
		}

		visit[nx][ny] = 0;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	visit[spot[0].X][spot[0].Y] = 1;
	go(spot[0], 1);

	cout << res << "\n";

	return 0;
}