#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

class Deque
{
private:
	int arr[MAX];
	int begin, end;
public:

	Deque() :begin(MAX/2), end(MAX/2)
	{}

	void push_front(int n);
	void push_back(int n);
	void pop_front();
	void pop_back();
	int front();
	int back();
	bool empty();
	int size();
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	Deque d;
	cin >> n;
	//cin.ignore();

	while (n--)
	{
		string str;

		cin >> str;
		if (str == "push_back")
		{
			int tmp;
			cin >> tmp;
			d.push_back(tmp);
		}
		else if (str == "push_front")
		{
			int tmp;
			cin >> tmp;
			d.push_front(tmp);
		}
		else if (str == "front")
		{
			cout << d.front() << '\n';
		}
		else if (str == "back")
		{
			cout << d.back() << '\n';
		}
		else if (str == "size")
		{
			cout << d.size() << '\n';
		}
		else if (str == "empty")
		{
			cout << d.empty() << '\n';
		}
		else if (str == "pop_front")
		{
			cout << d.front() << '\n';
			d.pop_front();
		}
		else if (str == "pop_back")
		{
			cout << d.back() << '\n';
			d.pop_back();
		}
	}

	return 0;
}

void Deque::push_front(int n)
{
	arr[begin--] = n;
}
void Deque::push_back(int n)
{
	arr[++end] = n;
}
void Deque::pop_front()
{
	if (empty())
		return;
	begin++;
}
void Deque::pop_back()
{
	if (empty())
		return;
	end--;
}
int Deque::front()
{
	if (empty())
		return -1;
	return arr[begin + 1];
}
int Deque::back()
{
	if (empty())
		return -1;
	return arr[end];
}
bool Deque::empty()
{
	if (end == begin)
		return true;
	return false;
}
int Deque::size()
{
	return end - begin;
}