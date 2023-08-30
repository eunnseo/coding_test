#include <iostream>
#include <deque>
using namespace std;

#define NUM_WHEEL 4
#define NUM_STATE 8

deque<deque<int>> wheel(NUM_WHEEL, deque<int>(NUM_STATE, 0));
int rot[4] = {0, 0, 0, 0};

void rotate(int num, int dir)
{
    if (dir == 1) // cw
    {
        int tmp = wheel[num].back();
        wheel[num].pop_back();
        wheel[num].push_front(tmp);
    }
    else if (dir == -1) // ccw
    {
        int tmp = wheel[num].front();
        wheel[num].pop_front();
        wheel[num].push_back(tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < NUM_WHEEL; i++)
    {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < NUM_STATE; j++)
        {
            wheel[i][j] = tmp[j] - '0';
        }
    }

    int left = 6;
    int right = 2;

    int k;
    cin >> k;
    while (k--)
    {
        for (int i = 0; i < 4; i++) rot[i] = 0;

        int num, dir, tmp_dir;
        cin >> num >> dir;
        num--;
        rot[num] = dir;
        
        // check left
        tmp_dir = -dir;
        for (int i = num - 1; i >= 0; i--)
        {
            if (wheel[i][right] != wheel[i+1][left])
            {
                rot[i] = tmp_dir;
                tmp_dir = -tmp_dir;
            }
            else
            {
                break;
            }
        }

        // check right
        tmp_dir = -dir;
        for (int i = num + 1; i < NUM_WHEEL; i++)
        {
            if (wheel[i-1][right] != wheel[i][left])
            {
                rot[i] = tmp_dir;
                tmp_dir = -tmp_dir;
            }
            else
            {
                break;
            }
        }

        // rotate
        for (int i = 0; i < NUM_WHEEL; i++)
        {
            if (rot[i] == 0) continue;
            rotate(i, rot[i]);
        }
    }

    int res = 0;
    for (int i = 0; i < NUM_WHEEL; i++)
    {
        if (wheel[i][0]) res += (1 << i);
    }
    cout << res;

    return 0;
}