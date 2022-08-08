#include <iostream>
using namespace std;

int a[100001];
long long d[100001];
long long d2[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	//i번째 수로 끝나는 경우.
	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i];
		if (i == 1)continue;

		if (d[i] < d[i - 1] + a[i])
			d[i] = d[i - 1] + a[i];
	}

	//i번째 수로 시작하는 경우.
	for (int i = n; i >= 1; i--)
	{
		d2[i] = a[i];
		if (i == n)continue;

		if (d2[i] < d2[i + 1] + a[i])
			d2[i] = d2[i + 1] + a[i];
	}

	int max = d[1];

	for (int i = 2; i <= n; i++)
	{
		if (max < d[i])
			max = d[i];
	}

	for (int i = 2; i <= n - 1; i++)
	{
		if (max < d[i - 1] + d2[i + 1])
			max = d[i - 1] + d2[i + 1];
	}

	cout << max << '\n';

	return 0;
}

// d[i] = i번째 수가 포함 + a[i]로 끝나는 최대 연속합.
// d2[i] = i번째 수가 포함 + a[i]로 시작하는 최대 연속합.