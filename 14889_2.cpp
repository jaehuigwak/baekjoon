#include <iostream>
#include <vector>
using namespace std;

int s[20][20];
int go(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}

	cout << go(n);

	return 0;
}

int go(int n)
{
	int min = 2000;
	
	for (int i = 1; i < (1 << n); i++) //모든 부분 수열 탐색
	{
		vector<int> first;
		vector<int> second;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				first.push_back(j);
			}
			else
			{
				second.push_back(j);
			}
		}

		if (first.size() == n / 2 && second.size() == n / 2)
		{
			int a = 0;
			int b = 0;

			for (int i = 0; i < n / 2; i++)
			{
				for (int j = 0; j < n / 2; j++)
				{
					if (i == j)
						continue;

					a += s[first[i]][first[j]];
					b += s[second[i]][second[j]];
				}
			}

			int ans = a > b ? a - b : b - a;
			if (min > ans)
			{
				min = ans;
			}
		}
	}

	return min;
}