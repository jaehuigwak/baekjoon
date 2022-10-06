#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>>map;
int maze[100][100];
int dis[100][100];

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs(int x, int y, int n, int m);

int main()
{	
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	bfs(0, 0, n, m);

	cout << dis[n - 1][m - 1] << '\n';

	return 0;
}


void bfs(int x, int y,int n, int m)
{
	dis[x][y] = 1; map.push({ x,y });

	while (!map.empty())
	{
		int x = map.front().first; int y = map.front().second;
		map.pop();

		for (int i = 0; i < 4; i++)
		{
			int X = dx[i] + x; int Y = dy[i] + y;
			if (X >= 0 && X < n && Y >= 0 && Y < m)
			{
				if (maze[X][Y] == 1 && dis[X][Y] == 0)
				{					
					dis[X][Y] = dis[x][y] + 1; map.push({X,Y});
				}
			}
		}
	}

}