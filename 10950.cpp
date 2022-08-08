#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	int a, b;

	cin >> num;
	while (num--)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}



	return 0;
}