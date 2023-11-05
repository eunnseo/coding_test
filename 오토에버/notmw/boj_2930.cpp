#include <iostream>
using namespace std;

int r, n;

int rsp(char sang, char fr)
{
    if (sang == 'R')
    {
        if (fr == 'R') return 1;
        else if (fr == 'S') return 2;
        else if (fr == 'P') return 0;
        else ; /* do nothing */
    }
    else if (sang == 'S')
    {
        if (fr == 'R') return 0;
        else if (fr == 'S') return 1;
        else if (fr == 'P') return 2;
        else ; /* do nothing */
    }
    else if (sang == 'P')
    {
        if (fr == 'R') return 2;
        else if (fr == 'S') return 0;
        else if (fr == 'P') return 1;
        else ; /* do nothing */
    }
    else
    {
        /* do nothing*/
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string sang_arr;
    string fr_arr[55];

    cin >> r >> sang_arr >> n;
    for (int i = 0; i < n; i++) cin >> fr_arr[i];

    int score = 0;
    for (int f = 0; f < n; f++)
    {
        for (int i = 0; i < r; i++)
        {
            score += rsp(sang_arr[i], fr_arr[f][i]);
        }
    }
    cout << score << "\n";

    score = 0;
    for (int i = 0; i < r; i++)
    {
        int max_score = 0;

        int tmp_score = 0;
        for (int j = 0; j < n; j++)
            tmp_score += rsp('R', fr_arr[j][i]);
        if (tmp_score > max_score)
            max_score = tmp_score;

        tmp_score = 0;
        for (int j = 0; j < n; j++)
            tmp_score += rsp('S', fr_arr[j][i]);
        if (tmp_score > max_score)
            max_score = tmp_score;

        tmp_score = 0;
        for (int j = 0; j < n; j++)
            tmp_score += rsp('P', fr_arr[j][i]);
        if (tmp_score > max_score)
            max_score = tmp_score;

        score += max_score;
    }
    cout << score << "\n";

    return 0;
}