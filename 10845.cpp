#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
	int que[10000];
	int begin, end;
public:
	Queue():begin(0),end(0)
	{}
	void push(int x);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();

	Queue que;

	while (n--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int tmp;
			cin >> tmp;
			que.push(tmp);
		}
		else if (cmd == "pop")
		{
			cout << que.pop() << '\n';
		}
		else if (cmd == "front")
		{
			cout << que.front() << '\n';
		}
		else if (cmd == "back")
		{
			cout << que.back() << '\n';
		}
		else if (cmd == "size")
		{
			cout << que.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << que.empty() << '\n';
		}
	}

	return 0;
}

void Queue::push(int x)
{
	que[end++] = x;

}
int Queue::pop()
{
	if (empty())
		return -1;
	else
		return que[begin++];
}
int Queue::size()
{
	return end - begin;
}
bool Queue::empty()
{
	if (end == begin)
		return true;
	return false;
}
int Queue::front()
{
	if (empty())
		return -1;
	return que[begin];
}
int Queue::back()
{
	if (empty())
		return -1;
	return que[end-1];
}