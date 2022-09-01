#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//bool perm(vector<int>& arr);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int ans = 0;

	do
	{
		int sum = 0;
		for (int i = 0; i < n-1; i++)
		{
			sum += abs(v[i] - v[i + 1]);
		}

		if (ans < sum)
			ans = sum;

	} while (next_permutation(v.begin(),v.end()));

	cout << ans << '\n';

	return 0;
}

//bool perm(vector<int>& arr)
//{
//	int i = arr.size() - 1;
//	while (i > 0 && arr[i - 1] >= arr[i])
//	{
//		i--;
//	}
//	if (i <= 0)
//		return false;
//
//	int j = i;
//	for (int k = i; k < arr.size() - 1; k++)
//	{
//		if (arr[i - 1] <= arr[k])
//		{
//			j = k;
//		}
//	}
//
//	swap(arr[i - 1], arr[j]);
//
//	reverse(arr.begin() + i, arr.end());
//
//	return true;
//}