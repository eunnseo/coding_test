// ÀÌºĞÅ½»ö

#include<iostream>
#include <algorithm>
using namespace std;

int n, q;
int car[500002];

int binary_search(int target)
{
	int st = 0;
	int mid = 0;
	int en = n - 1;

	while (st <= en)
	{
		mid = (st + en) / 2;

		if (target == car[mid])
		{
			return mid;
		}
		else if (target < car[mid])
		{
			en = mid - 1;
		}
		else
		{
			st = mid + 1;
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> car[i];

	sort(car, car + n);

	while (q--)
	{
		int m;
		cin >> m;
		
		int idx = binary_search(m);

		if (idx > 0) cout << idx * (n - idx - 1) << "\n";
		else cout << "0\n";
	}

	return 0;
}