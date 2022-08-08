#include <iostream>
using namespace std;

int a[1001];
int d[1001];
int v[1001]; // a[i]���� ���� ���ؽ� ��ȣ. 
//ex) 10 20 10 30 50���� a[i]�� 30�϶�, v[i]�� 20�� ����Ű�� a[i]�� �ε��� ��ȣ.

void go(int p);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int count = 1;

    for (int i = 1; i <= n; i++)
    {
        int max = 0;

        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && max < d[j])
            {
				max = d[j]; // ���� �ε������� ���� �ִ� Ƚ��
				v[i] = j;
            }
        }

        d[i] = max + 1;
    }

    int max = 0;
    int idx = 0;

    for (int i = 1; i <= n; i++)
    {
        if (max < d[i])
        {
            max = d[i];
            idx = i; // �ִ� Ƚ���� ���� d[i]�� a[i]�ε���
        }
    }
    cout << max << '\n';

    go(idx);

    return 0;
}

void go(int p)
{
    if (p <= 0)
        return;

    go(v[p]); //�ִ� Ƚ���� ���� d[i]�� a[i]�� ���� �ε����� ����.
    cout << a[p] << ' ';
}