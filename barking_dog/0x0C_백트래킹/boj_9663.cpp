#include <iostream>
using namespace std;

int n = 0;
int cnt = 0;
bool isused1[15]; // 열
bool isused2[30]; // 왼쪽아래 -> 오른쪽위 대각선
bool isused3[30]; // 왼쪽위 -> 오른쪽아래 대각선

void func(int row)
{
    if (row == n)
    {
        cnt++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (!isused1[col] && !isused2[row+col] && !isused3[row-col+n-1])
        {
            isused1[col] = true;
            isused2[row+col] = true;
            isused3[row-col+n-1] = true;
            func(row+1);
            isused1[col] = false;
            isused2[row+col] = false;
            isused3[row-col+n-1] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt;

    return 0;
}