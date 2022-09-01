#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool permutation(vector<int>& a);

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

	if (permutation(v))
	{
		for (int& t : v)
		{
			cout << t << ' ';
		}

	}
	else
	{
		cout << -1;
	}

	cout << '\n';

	return 0;
}

bool permutation(vector<int>& a)
{
	int i = (int)a.size() - 1;

	while (i > 0 && a[i - 1]<=a[i])
	{
		i--;
	}
	if (i <= 0)
		return false;

	int j;

	for (int k = i; k <a.size(); k++)
	{
		if (a[i - 1] >= a[k])
		{
			j = k;
		}
	}

	swap(a[i - 1], a[j]);

	reverse(a.begin() + i, a.end());

	return true;

}