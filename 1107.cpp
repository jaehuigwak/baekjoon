#include <iostream>
using namespace std;

bool brk[15];
int possible(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int ans;

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		brk[tmp] = true;
	}

	ans = (n - 100) > 0 ? (n - 100) : (100 - n); //100번에서 +,-연상 횟수
	int p = possible(n);

	if (p) //고장난 버튼이 없는 경우
	{
		if (ans > p)
			ans = p;
	}
	else // 버튼이 고장난 경우
	{
		for (int i = 0; i < 1000000; i++)
		{
			int len = possible(i);
			if (len)
			{
				len += (i - n) > 0 ? (i - n) : (n - i); 

				if (ans > len)
					ans = len;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}

int possible(int n)
{
	int len = 0;
	
	if (n == 0)
	{
		if (brk[n])
			return false;
		else
			return len = 1;
	}
	else
	{
		while (n > 0)
		{
			if (brk[n % 10])
				return false;
			len++;
			n /= 10;
		}
	}
	
	return len;
}