#include <iostream>
using namespace std;

class getResult
{
private:
	int x, y;
public:
	getResult() :x(0), y(0)
	{}

	int getGCD()
	{
		int a = x, b = y;
		while (b != 0)
		{
			a = b;
			b = a % b;			
		}
		return a;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;


	}


	return 0;
}