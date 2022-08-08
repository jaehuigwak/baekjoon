#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
	int arr[100000];
	int cnt;
public:
	Stack() :cnt(0)
	{}
	void push(int n);
	void pop();
	int top();
	bool empty();

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int n, max = -1;
	int tmp = 1;
	string result;
	Stack s;
	cin >> n;

	while (n--)
	{
		int in;
		cin >> in;
		
		if (max <= in)
			max = in;

		while ()
		{

		}

		tmp = s.top();

	}

	return 0;
}

void Stack::push(int n)
{
	arr[cnt++] = n;
}
void Stack::pop()
{
	if (empty())
		return;
	cnt--;
}
int Stack::top()
{
	if (empty())
		return -1;
	return arr[cnt - 1];
}
bool Stack::empty()
{
	if (cnt <= 0)
		return true;
	return false;
}