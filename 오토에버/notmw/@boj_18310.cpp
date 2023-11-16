#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n;
ll arr[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (ll i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    if (n % 2 == 0)
        cout << arr[n/2-1];
    else
        cout << arr[n/2];

    return 0;
}

// ref: https://blog.naver.com/PostView.naver?blogId=jinhan814&logNo=222534711709&parentCategoryNo=&categoryNo=11&viewDate=&isShowPopularPosts=false&from=postView