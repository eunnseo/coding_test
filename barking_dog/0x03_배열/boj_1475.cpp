// ¹æ ¹øÈ£
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long int num;
    cin >> num;

    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }

    while (num != 0)
    {
        arr[num % 10]++;
        num /= 10;
    }

    /* my solution */
    int six_nine = 0;
    if ((arr[6] + arr[9]) % 2 == 0) // Â¦¼ö
    {
        six_nine = (arr[6] + arr[9]) / 2;
    }
    else // È¦¼ö
    {
        six_nine = (arr[6] + arr[9]) / 2 + 1;
    }
    arr[6] = six_nine; // 6
    arr[9] = six_nine; // 9
    /*************/

    /* BaaaaaaaaaaarkingDog solution */
    // int six_nine = (arr[6] + arr[9] + 1) / 2;
    // arr[6] = six_nine;
    // arr[9] = six_nine;
    /*************/

    int max_idx = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > arr[max_idx])
        {
            max_idx = i;
        }
    }

    cout << arr[max_idx] << "\n";

    return 0;
}