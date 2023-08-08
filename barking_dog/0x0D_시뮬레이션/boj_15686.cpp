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
vector<pair<int, int>> picked(14);
int isused[14];

void printHouses()
{
    cout << "houses > " << endl;
    for (auto iter = houses.begin(); iter != houses.end(); iter++)
    {
        cout << "(" << iter->X << ", " << iter->Y << ") | ";
    }
    cout << endl;
}
void printChickens()
{
    cout << "chickens > " << endl;
    for (auto iter = chickens.begin(); iter != chickens.end(); iter++)
    {
        cout << "(" << iter->X << ", " << iter->Y << ") | ";
    }
    cout << endl;
}
void printPicked()
{
    cout << "picked > " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << "(" << picked[i].X << ", " << picked[i].Y << ") | ";
    }
    cout << endl;
}
void printIsused()
{
    cout << "isused > " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << isused[i] << ", ";
    }
    cout << endl;
}

void calcCityChickenDist()
{
    int ccd = 0; // 도시의 치킨 거리
    for (auto h = houses.begin(); h != houses.end(); h++)
    {
        int cd = 50 * 50; // 치킨 거리
        for (int i = 0; i < M; i++)
        {
            int d = abs(h->X - picked[i].X) + abs(h->Y - picked[i].Y);
            if (d < cd) cd = d;
        }
        ccd += cd;
        if (min_ccd < ccd) return;
    }
    if (min_ccd > ccd) min_ccd = ccd;
    return;
}

void run(int idx, int start)
{
    cout << "idx = " << idx << ", start = " << start << endl;
    printPicked();
    printIsused();
    cout << endl;

    if (idx == M)
    {
        cout << "!!!!!!!!!! idx == M !!!!!!!!!!" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        calcCityChickenDist();
        cout << endl;
        return;
    }

    for (int i = start; i < chickens.size(); i++)
    {
        if (!isused[i])
        {
            cout << "idx = " << idx << ", start = " << start << ", i = " << i << endl;
            cout << endl;
            isused[i] = true;
            picked[idx] = chickens[i];
            run(idx + 1, i);
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

    printHouses();
    printChickens();
    cout << endl;

    run(0, 0);
    cout << min_ccd;

    return 0;
}