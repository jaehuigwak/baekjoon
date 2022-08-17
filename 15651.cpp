#include <iostream>
using namespace std;

int arr[10];
void go(int idx,int n, int m);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	go(0, n, m);

	return 0;
}

void go(int idx,int n, int m)
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

	for (int i = 1; i <= n; i++)
	{
		arr[idx] = i;
		go(idx + 1, n, m);
	}
}