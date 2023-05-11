#include <iostream>
using namespace std;

int func2(int arr[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if ((arr[i] + arr[j]) == 100)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int arr1[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87};

    std::cout << func2(arr1, 3) << std::endl;
    std::cout << func2(arr2, 2) << std::endl;
    std::cout << func2(arr3, 4) << std::endl;

    return 0;
}

// 시간복잡도: O(N^2)