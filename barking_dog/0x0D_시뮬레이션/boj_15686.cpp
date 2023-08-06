#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int N, M;
int min_ccd = 50 * 50 * 13;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<pair<int, int>> arr(14);
int isused[14];

void calcCityChickenDist()
{
    int ccd = 0; // 도시의 치킨 거리
    for (auto h = houses.begin(); h != houses.end(); h++)
    {
        int cd = 50 * 50; // 치킨 거리
        for (int i = 0; i < M; i++)
        {
            int d = abs(h->X - arr[i].X) + abs(h->Y - arr[i].Y);
            if (d < cd) cd = d;
        }
        ccd += cd;
        if (min_ccd < ccd) return;
    }
    if (min_ccd > ccd) min_ccd = ccd;
    return;
}

void run(int idx)
{
    if (idx == M)
    {
        calcCityChickenDist();
        return;
    }

    for (int i = idx; i < chickens.size(); i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            arr[idx] = chickens[i];
            run(idx + 1);
            isused[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1) houses.push_back({r, c});
            else if (tmp == 2) chickens.push_back({r, c});
        }
    }

    run(0);
    cout << min_ccd;

    return 0;
}