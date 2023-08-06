#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

int N, M, K, R, C;
vector<vector<int>> notebook(41, vector<int>(41));
vector<vector<int>> backup(41, vector<int>(41));
vector<vector<int>> sticker(11, vector<int>(11));
vector<vector<int>> tmp_sticker(11, vector<int>(11));

void rotateSticker(int &row, int &col);
bool addSticker(pair<int, int> start);
bool searchNotebook();
int countOne();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    while (K--)
    {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> sticker[i][j];

        bool ok = searchNotebook();
        if (!ok)
        {
            for (int i = 0; i < 3; i++)
            {
                rotateSticker(R, C);
                ok = searchNotebook();
                if (ok) break;
            }
        }
    }

    cout << countOne();

    return 0;
}

void rotateSticker(int &row, int &col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            tmp_sticker[j][row-i-1] = sticker[i][j];

    sticker.resize(col, vector<int>(row));
    sticker = tmp_sticker;

    int tmp = row;
    row = col;
    col = tmp;
}
bool addSticker(pair<int, int> start)
{
    backup = notebook;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int tmp = notebook[start.X + i][start.Y + j] + sticker[i][j];
            if (tmp > 1)
            {
                notebook = backup;
                return false;
            }
            notebook[start.X + i][start.Y + j] = tmp;
        }
    }
    return true;
}
bool searchNotebook()
{
    int row = N - R + 1;
    int col = M - C + 1;

    if (row <= 0 || col <= 0) return false;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            bool ok = addSticker({i, j});
            if (ok) return true;
        }
    }
    return false;
}
int countOne()
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (notebook[i][j] == 1) res++;
        }
    }
    return res;
}
