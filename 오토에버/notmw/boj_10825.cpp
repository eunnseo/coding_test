#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    string name;
    int kor;
    int eng;
    int math;
};

int n;
Node arr[100005];

bool cmp(Node a, Node b)
{
    if (a.kor == b.kor)
    {
        if (a.eng == b.eng)
        {
            if (a.math == b.math)
            {
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.eng < b.eng;
    }
    return a.kor > b.kor;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
        cout << arr[i].name << "\n";

    return 0;
}