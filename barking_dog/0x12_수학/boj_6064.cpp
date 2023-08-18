#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int k = 1;
        int a = 0;
        int b = 0;
        int max_k = m * n / gcd(m, n);

        while (1)
        {
            int left = x + m * a;
            int right = y + n * b;

            if ((left > max_k) || (right > max_k))
            {
                cout << "-1\n";
                break;
            }

            if (left == right)
            {
                cout << left << "\n";
                break;
            }
            else if (left > right)
            {
                b++;
            }
            else if (left < right)
            {
                a++;
            }
        }
    }

    return 0;
}

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int m, n, x, y;
//         cin >> m >> n >> x >> y;

//         int x2 = 1;
//         int y2 = 1;
//         int k = 1;
//         while (1)
//         {
//             if (x2 == m && y2 == n)
//             {
//                 if (x2 == x && y2 == y) cout << k << "\n";
//                 else cout << "-1\n";
//                 break;
//             }
//             else if (x2 == x && y2 == y)
//             {
//                 cout << k << "\n";
//                 break;
//             }

//             if (x2 < m) x2++;
//             else x2 = 1;

//             if (y2 < n) y2++;
//             else y2 = 1;

//             k++;
//         }
//     }

//     return 0;
// }