#include <iostream>
using namespace std;

int func1(int N)
{
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            result += i;
        }
    }
    return result;
}

int main()
{
    std::cout << func1(16) << std::endl;
    std::cout << func1(34567) << std::endl;
    std::cout << func1(27639) << std::endl;

    return 0;
}

// 시간복잡도 O(N)