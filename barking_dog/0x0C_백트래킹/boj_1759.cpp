#include <bits/stdc++.h>
using namespace std;

int l, c;
char in[17];
int pw_idx[17];
bool isused[17];

void input()
{
    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> in[i];
    }
}

bool isPassword()
{
    int mo = 0;
    int za = 0;
    for (int i = 0; i < l; i++)
    {
        if (in[pw_idx[i]] == 'a' || in[pw_idx[i]] == 'e' || in[pw_idx[i]] == 'i' || in[pw_idx[i]] == 'o' || in[pw_idx[i]] == 'u')
            mo++;
        else
            za++;
    }
    if (mo >= 1 && za >= 2) return true;
    else return false;
}

void run(int idx)
{
    if (idx == l)
    {
        if (isPassword())
        {
            for (int i = 0; i < l; i++)
                cout << in[pw_idx[i]];
            cout << "\n";
        }
        return;
    }

    int st = pw_idx[idx-1];
    for (int i = st; i < c; i++)
    {
        if (!isused[i])
        {
            isused[i] = 1;
            pw_idx[idx] = i;
            run(idx + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    sort(in, in+c);
    run(0);

    return 0;
}