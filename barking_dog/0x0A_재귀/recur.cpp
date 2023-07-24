#include <iostream>
using namespace std;

void func1(int n)
{
    if (n == 0) return;
    cout << n << ' ';
    func1(n-1);
}
void func2(int n)
{
    if (n == 0) return;
    func2(n-1);
    cout << n << ' ';
}

int main()
{
    func1(3);
    cout << endl;
    
    func2(3);
    cout << endl;

    return 0;
}