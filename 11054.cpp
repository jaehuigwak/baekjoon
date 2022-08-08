#include <iostream>
using namespace std;

int a[1001];
int l[1001];
int r[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 증가 수열의 최대 길이 구하기(오른쪽 방향)
    for (int i = 1; i <= n; i++)
    {
        r[i] = 1;

        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && r[i] < r[j] + 1)
            {
                r[i] = r[j] + 1;
            }
        }
    }

    //증가 수열의 최대 길이 구하기(왼쪽 방향)
    for (int i = n; i >=1; i--)
    {
        l[i] = 1;

        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j] && l[i] < l[j] + 1)
            {
                l[i] = l[j] + 1;
            }
        }
    }

    int max = r[1] + l[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        if (max < r[i] + l[i] - 1)
            max = r[i] + l[i] - 1;
    }

    cout << max << '\n';

    return 0;
}