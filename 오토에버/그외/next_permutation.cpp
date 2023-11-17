#include <iostream>
#include <algorithm>
using namespace std;

int n = 5;
// int a[3] = {1, 1, 3};
int a[5] = {0, 0, 0, 1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 순열
    // do {
    //     for (int i = 0; i < n; i++)
    //         cout << a[i] << " ";
    //     cout << endl;
    // } while (next_permutation(a, a+n));

    // 조합
    do {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                cout << i+1 << " ";
        }
        cout << endl;
    } while (next_permutation(a, a+n));

    return 0;
}