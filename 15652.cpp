#include <iostream>
using namespace std;

int arr[10];
void go(int start,int idx,int n, int m);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	go(1, 0, n, m);

	return 0;
}

void go(int start, int idx, int n, int m)
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


	for (int i = start; i <= n; i++)
	{
		arr[idx] = i;
		go(i, idx + 1, n, m);
	}
}