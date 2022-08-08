#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Change
{
private:
	string num;
	int length;

public:
	Change(string n) :num(n)
	{
		length = (int)n.size();
	}

	long change2to10()
	{
		long result = 0;
		for (int i = 0; i < length; i++)
		{
			result += (num[i]-'0')*pow(2, length - i-1);
		}
		return result;
	}

	long change10to8()
	{
		long tmp=change2to10();
		long result=0;
		int i = 0;		
		do 
		{
			result += (tmp % 8)*pow(10,i++);
			tmp /= 8;

		} while (tmp!= 0);

		return result;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string n;
	getline(cin,n);

	Change c(n);
	cout << c.change10to8() << '\n';


	return 0;
}


