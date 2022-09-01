#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;
bool permutation();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	if (permutation())
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i];
			if (i != v.size() - 1)
			{
				cout << ' ';
			}
		}
		cout << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}


	return 0;
}

bool permutation()
{
	int i = v.size() - 1;
	while (v[i] <= v[i - 1] && i > 0)
	{
		i--;
	}

	if (i <= 0)
		return false;

	int j = v.size() - 1;

	while (v[j] <= v[i - 1])
	{
		j--;
	}

	swap(v[i - 1], v[j]);

	reverse(v.begin() + i, v.end());

	return true;
}