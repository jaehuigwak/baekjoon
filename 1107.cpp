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

	ans = (n - 100) > 0 ? (n - 100) : (100 - n); //100������ +,-���� Ƚ��
	int p = possible(n);

	if (p) //���峭 ��ư�� ���� ���
	{
		if (ans > p)
			ans = p;
	}
	else // ��ư�� ���峭 ���
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