#include <iostream>
using namespace std;

int func4(int N)
{
    int result = 1;
    for (int i = 1; result * 2 <= N; i++)
    {
        result *= 2;
    }
    return result;
}

int main()
{
    std::cout << func4(5) << std::endl;
    std::cout << func4(97615282) << std::endl;
    std::cout << func4(1024) << std::endl;

    return 0;
}

// 시간복잡도: O(logN)