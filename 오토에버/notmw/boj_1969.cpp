#include <iostream>
using namespace std;

int n, m;
string arr[1005];
int cnt[5];

string res_dna = string();
int res_cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 4; j++) cnt[j] = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == 'A') cnt[0]++;
            else if (arr[j][i] == 'C') cnt[1]++;
            else if (arr[j][i] == 'G') cnt[2]++;
            else if (arr[j][i] == 'T') cnt[3]++;
            else ;
        }

        int max_cnt = 0;
        int max_idx = 0;
        for (int j = 0; j < 4; j++)
        {
            if (cnt[j] > max_cnt)
            {
                max_cnt = cnt[j];
                max_idx = j;
            }
        }

        if (max_idx == 0) res_dna += 'A';
        else if (max_idx == 1) res_dna += 'C';
        else if (max_idx == 2) res_dna += 'G';
        else if (max_idx == 3) res_dna += 'T';
        else ;

        res_cnt += (n - max_cnt);
    }

    cout << res_dna << "\n" << res_cnt;

    return 0;
}