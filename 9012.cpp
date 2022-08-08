#include <iostream>
#include <string>
using namespace std;

class strStack
{
private:
	char bracket[60];
	int cnt;

public:
	strStack() :cnt(0)
	{}

	void push(char ch);
	bool pop();
	char top();
	bool empty();
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	bool check = false;

	cin >> num;
	cin.ignore();

	while (num--)
	{
		strStack stack;
		string str;
		getline(cin,str);

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
			{
				stack.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (stack.pop())
				{
					check = true;
				}
				else
				{
					check = false;
				}
				
			}
		}

		if (check&&stack.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

	}


	return 0;
}

void strStack::push(char ch)
{
	bracket[cnt++] = ch;
}
bool strStack::pop()
{
	if (empty())
		return false;

	bracket[--cnt] = '\0';
	return true;
}
char strStack::top()
{
	return bracket[cnt - 1];
}
bool strStack::empty()
{
	if (cnt != 0)
		return false;
	return true;
}