#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); // printf 방식과 cout 방식의 동기화를 하지 않도록 설정 (printf, scanf 사용 금지)
    cin.tie(0); // 버퍼를 비우지 않도록 설정

    string s;
    cin >> s;

    int arr[30];
    for (int i = 0; i < 30; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        arr[idx]++;
    }

    int num = 'z' - 'a' + 1;
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}