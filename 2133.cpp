#include <iostream>
using namespace std;

int d[31][5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	d[2][1] = 1;
	d[2][2] = 1;
	d[4][3] = 1;
	d[4][4] = 1;

	for (int i = 3; i <= n; i++)
	{
		if (i - 2 >= 4)
		{
			d[i][1] = d[i - 2][1] + d[i - 2][2] + d[i - 2][3] + d[i - 2][4];
			d[i][2] = d[i - 2][1] + d[i - 2][2] + d[i - 2][3] + d[i - 2][4];
		}
		else
		{
			d[i][1] = d[i - 2][1] + d[i - 2][2];
			d[i][2] = d[i - 2][1] + d[i - 2][2];
		}

		if (i - 4 > 0)
		{
			d[i][3] = d[i - 4][1] + d[i - 4][2] + d[i - 4][3] + d[i - 4][4];
		}
	}

	cout << d[n][1] + d[n][2] + d[n][3] << '\n';

	return 0;
}

//d[i][1] : 가로가 2인 경우의 수, 1번 블록 두개에 2번 블록 한개
//d[i][2] : 가로가 2인 경우의 수, 2번 블록 세개
//d[i][3] : 가로가 4인 경우의 수