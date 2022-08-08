#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:

	char arr[1000000]; //백준에서는 주어진 수의 크기보다 많은 배열을 형성해야 정답처리가 된다.
	int cnt;

public:
	Stack() :cnt(0)
	{}

	void push(char m)
	{
		arr[cnt++] = m;
	}
	void pop()
	{
		if (empty())
			return;
		arr[--cnt] = 0;
	}
	char top()
	{
		if (empty())
			return 0;

		return arr[cnt - 1];
	}
	bool empty()
	{
		if (cnt <= 0)
			return true;
		return false;
	}

};



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Stack left,right;
	string str;
	char cmd;
	int n;

	getline(cin, str);

	for (int i = 0; i < (int)str.size(); i++)
	{
		left.push(str[i]);
	}

	cin >> n;
	while (n--)
	{
		cin >> cmd;
		
		switch (cmd)
		{
		case 'P':
			char input;
			cin >> input;
			
			left.push(input);

			break;
		case 'L':
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
			break;
		case 'B':
			if (!left.empty())
			{
				left.pop();
			}
			break;
		}
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}

	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}

	cout << '\n';

	return 0;
}