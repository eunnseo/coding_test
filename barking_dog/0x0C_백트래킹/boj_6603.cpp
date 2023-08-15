#include <iostream>
using namespace std;

int k;
int arr[6];
int isused[15];
int input[15];

void func(int idx, int start)
{
    if (idx == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < k; i++)
    {
        if (!isused[i])
        {
            isused[i] = true;
            arr[idx] = input[i];
            func(idx + 1, i);
            isused[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        for (int i = 0; i < 6; i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i < 15; i++)
        {
            isused[i] = 0;
            input[i] = 0;
        }


        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++)
        {
            cin >> input[i];
        }

        func(0, 0);
        cout << "\n";
    }

    return 0;
}