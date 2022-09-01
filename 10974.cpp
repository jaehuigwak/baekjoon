#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool perm(vector<int>& arr);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v;

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	do
	{
		for (int& t : v)
		{
			cout << t << ' ';
		}
		cout << '\n';

	} while (perm(v));

	return 0;
}

bool perm(vector<int>& arr)
{
	int i=arr.size()-1;
	while (i > 0 && arr[i - 1] >= arr[i])
	{
		i--;
	}
	if (i <= 0)
		return false;

	int j;
	for (int k = i; k < arr.size(); k++)
	{
		if (arr[i - 1] < arr[k])
		{
			j = k;
		}
	}

	swap(arr[i - 1], arr[j]);

	reverse(arr.begin() + i, arr.end());

	return true;
}