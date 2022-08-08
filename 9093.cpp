#include <iostream>
#include <string>
using namespace std;

class wordStack
{
private:
	char str[30];
	int cnt;
public:
	wordStack() :cnt(0)
	{}
	void pop();
	void push(char x);
	bool empty();
	char top();
	int size();
	char& operator[](int idx)
	{
		if (idx<0 || idx>cnt)
			exit(1);
		return str[idx];
	}

};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> num;
	cin.ignore();

	string str;
	wordStack word;

	while (num--)
	{
		getline(cin, str);
		str += '\n';

		string result;
				
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ' || str[i] == '\n')
			{
				while (!word.empty())
				{
					result += word.top();
					word.pop();
				}
					
				result += ' ';
			}
			else
			{
				word.push(str[i]);
			}				
		}

		/*while (!word.empty())
			result += word.pop();*/

		cout << result << '\n';
	}



	return 0;
}

void wordStack::pop()
{
	if (empty())
		return;
	else
		cnt--;
}
void wordStack::push(char x)
{
	str[cnt++] = x;
}
bool wordStack::empty()
{
	if (cnt != 0)
		return false;
	return true;
}
char wordStack::top()
{
	if (empty())
		return 0;
	else
		return str[cnt - 1];
}

int wordStack::size()
{
	return cnt;
}