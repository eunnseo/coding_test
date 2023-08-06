#include <iostream>
using namespace std;

int N = 0;
int max_num = 0;
int board[21][21];

void run(int idx);
void up();
void down();
void right();
void left();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    run(0);

    cout << max_num;
    return 0;
}

void run(int idx)
{
    if (idx == 5)
    {
        int num = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] > num) num = board[i][j];

        if (num > max_num) max_num = num;
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int backup[21][21];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                backup[i][j] = board[i][j];

        if (dir == 0) up();
        else if (dir == 1) down();
        else if (dir == 2) left();
        else if (dir == 3) right();

        run(idx + 1);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = backup[i][j];
    }
}

void up()
{
    // cout << "up.." << endl;

    for (int c = 0; c < N; c++)
    {
        int pos = 0;
        int val = 0;
        for (int r = 0; r < N; r++)
        {
            if (board[r][c] == 0) continue;
            
            if (val == 0)
            {
                val = board[r][c];
            }
            else if (val == board[r][c])
            {
                board[pos][c] = val << 1;
                pos++;
                val = 0;
            }
            else if (val != board[r][c])
            {
                board[pos][c] = val;
                pos++;
                val = board[r][c];
            }
        }

        if (val != 0) 
        {
            board[pos][c] = val;
            pos++;
        }
        while (pos < N)
        {
            board[pos][c] = 0;
            pos++;
        }
    }
}
void down()
{
    // cout << "down.." << endl;

    for (int c = 0; c < N; c++)
    {
        int pos = N-1;
        int val = 0;
        for (int r = N-1; r >= 0; r--)
        {
            if (board[r][c] == 0) continue;
            
            if (val == 0)
            {
                val = board[r][c];
            }
            else if (val == board[r][c])
            {
                board[pos][c] = val << 1;
                pos--;
                val = 0;
            }
            else if (val != board[r][c])
            {
                board[pos][c] = val;
                pos--;
                val = board[r][c];
            }
        }

        if (val != 0)
        {
            board[pos][c] = val;
            pos--;
        }
        while (pos >= 0)
        {
            board[pos][c] = 0;
            pos--;
        }
    }
}
void right()
{
    // cout << "right.." << endl;

    for (int r = 0; r < N; r++)
    {
        int pos = N-1;
        int val = 0;
        for (int c = N-1; c >= 0; c--)
        {
            if (board[r][c] == 0) continue;
            
            if (val == 0)
            {
                val = board[r][c];
            }
            else if (val == board[r][c])
            {
                board[r][pos] = val << 1;
                pos--;
                val = 0;
            }
            else if (val != board[r][c])
            {
                board[r][pos] = val;
                pos--;
                val = board[r][c];
            }
        }

        if (val != 0)
        {
            board[r][pos] = val;
            pos--;
        }
        while (pos >= 0)
        {
            board[r][pos] = 0;
            pos--;
        }
    }
}
void left()
{
    // cout << "left.." << endl;

    for (int r = 0; r < N; r++)
    {
        int pos = 0;
        int val = 0;
        for (int c = 0; c < N; c++)
        {
            if (board[r][c] == 0) continue;
            
            if (val == 0)
            {
                val = board[r][c];
            }
            else if (val == board[r][c])
            {
                board[r][pos] = val << 1;
                pos++;
                val = 0;
            }
            else if (val != board[r][c])
            {
                board[r][pos] = val;
                pos++;
                val = board[r][c];
            }
        }

        if (val != 0)
        {
            board[r][pos] = val;
            pos++;
        }
        while (pos < N)
        {
            board[r][pos] = 0;
            pos++;
        }
    }
}
