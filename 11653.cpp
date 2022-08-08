#include <iostream>
#define MAX 100
using namespace std;

int num[MAX];
bool prime[MAX];
int idx = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i < MAX; i++)
	{
		num[i] = i;
	}

	for (int i = 2; i < MAX; i++)
	{
		for (int j = i + i; j <MAX ; j += i)
		{
			num[i] = 0;
		}
	}

	if (n > 1)
	{
		while (n)
		{
			for (int i = 2; i < MAX; i++)
			{
				
			}
		}
	}

	return 0;
}