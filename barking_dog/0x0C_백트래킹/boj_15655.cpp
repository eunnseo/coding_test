#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> input;
int arr[10];
int isused[10];

void func(int idx, int start)
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < input.size(); i++)
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

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    sort(input.begin(), input.end());
    func(0, 0);

    return 0;
}