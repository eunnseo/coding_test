#include <iostream>
#include <cmath>

using namespace std;

int n, k;
int score[1000005];

double avg(int st, int en)
{
    int s = 0;
    double len = en - st + 1;
    for (int i = st-1; i < en; i++)
        s += score[i];
    return s / len;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> score[i];

    while (k--)
    {
        int st, en;
        cin >> st >> en;

        double avg_num = avg(st, en);
        avg_num *= 100;
        avg_num = round(avg_num);
        avg_num /= 100;
        printf("%0.2f\n", avg_num);
    }

    return 0;
}