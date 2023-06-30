#include <iostream>
using namespace std;

int my_func3(int N)
{
    int num = 1;
    while (1)
    {
        if (num * num == N)
        {
            return 1;
        }
        else if (num * num < N)
        {
            num++;
        }
        else
        {
            return 0;
        }
    }
}

int func3(int N)
{
    for (int i = 1; i * i <= N; i++)
    {
        if (i * i == N)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    std::cout << func3(9) << std::endl;
    std::cout << func3(693953651) << std::endl;
    std::cout << func3(756580036) << std::endl;

    return 0;
}

// 시간복잡도: O(N^(1/2))