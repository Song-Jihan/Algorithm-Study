#include <stdio.h>
#define MAX_SIZE 1001 * 1001 + 10
int n, m, map[1001][1001], temp[1001][1001] = {}, visited[1001][1001][2] = {};
int	dx[4] = {-1, 0, 1, 0};
int	dy[4] = {0, 1, 0, -1};
typedef struct
{
	int	y;
	int	x;
	int	wall;
}	queue;

queue	q[MAX_SIZE];

void bfs()
{
	int	x, y, nx, ny, wall, cur = -1, last = 0;

	q[last].x = 0;
	q[last].wall = 0;
	q[last++].y = 0;
	while (++cur < last && temp[n - 1][m - 1] == -1)
	{
		x = q[cur].x;
		y = q[cur].y;
		wall = q[cur].wall;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n)
			{
				if (map[ny][nx] == 1 && wall == 0 && !visited[ny][nx][wall + 1])
				{
					temp[ny][nx] = temp[y][x] + 1;
					q[last].y = ny;
					q[last].x = nx;
					q[last++].wall = 1;
					visited[ny][nx][wall + 1]++;
				}
				else if (map[ny][nx] == 0 && !visited[ny][nx][wall])
				{
					temp[ny][nx] = temp[y][x] + 1;
					q[last].y = ny;
					q[last].x = nx;
					q[last++].wall = wall;
					visited[ny][nx][wall]++;
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
			temp[i][j] = -1;
		}
	}
	temp[0][0] = 1;
	bfs();
	printf("%d\n", temp[n - 1][m - 1]);
	return (0);
}