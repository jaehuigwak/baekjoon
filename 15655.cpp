#include <iostream>
#include <algorithm>
using namespace std;

int num[10];
int arr[10];

void go(int start,int idx, int n, int m);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	sort(num, num + n);
	go(0, 0, n, m);

	return 0;
}

void go(int start,int idx, int n, int m)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i];
			if (i != m - 1)
				cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++)
	{
		arr[idx] = num[i];
		go(i + 1, idx + 1, n, m);
	}
}