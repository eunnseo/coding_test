#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> input;
int arr[10];
int isused[10];

void func(int idx)
{
    if (idx == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = 0; i < input.size(); i++)
    {
        // if (!isused[i] && input[i] != arr[idx])
        if (!isused[i] && input[i] != tmp)
        {
            isused[i] = true;
            arr[idx] = input[i];
            tmp = arr[idx];
            func(idx + 1);
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
    func(0);

    return 0;
}

// 참고: https://m.blog.naver.com/js568/221857286945