#include <iostream>
using namespace std;

//클래스로 구현하는 습관 들이기!!! 

const int MAX = 10000;
int iStack[MAX];
int cnt = 0;

void push(int x);
void pop();
void size();
bool empty();
void top();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> num;
	string command;

	while (num--)
	{
		cin >> command;
		if (command=="push")
		{
			int tmp;
			cin >> tmp;
			push(tmp);
		}
		else if (command=="top")
		{
			top();
		}
		else if (command=="size")
		{
			size();
		}
		else if (command=="empty")
		{
			cout << empty() << '\n';
		}
		else if (command=="pop")
		{
			pop();
		}
	}


	return 0;
}

void push(int x)
{
	iStack[cnt] = x;
	cnt++;
}
void pop()
{
	if (empty())
		cout << -1 << '\n';
	else
		cout << iStack[--cnt] << '\n';
}
void size()
{
	cout << cnt << '\n';
}
bool empty()
{
	if (cnt != 0)
		return false;
	return true;
}
void top()
{
	if (empty())
		cout << -1 << '\n';
	else
		cout << iStack[cnt - 1] << '\n';
}