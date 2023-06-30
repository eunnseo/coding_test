#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); // printf ��İ� cout ����� ����ȭ�� ���� �ʵ��� ���� (printf, scanf ��� ����)
    cin.tie(0); // ���۸� ����� �ʵ��� ����

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