#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000001

int board[301][301];
int front, rear;
int dx[8] = { -1,1,2,2,1,-1,-2,-2 },dy[8]={ 2,2,1,-1,-2,-2,-1,1 };
int l, xstart, ystart, xend, yend;
typedef struct QueueType {
	int x, y;
}QueueType;

QueueType q[MAX];

void enqueue(int x,int y) {
	rear = (rear + 1) % MAX;
	q[rear].x = x;
	q[rear].y = y;
}

QueueType dequeue() {
	front = (front + 1) % MAX;
	return q[front];
}

void bfs(int x, int y) {
	int nx, ny;
	QueueType tmp;
	enqueue(x, y);
	board[ystart][xstart] = 1;
	while (front != rear) {
		tmp = dequeue();
		for (int i = 0; i < 8; i++) {
			nx = tmp.x + dx[i];
			ny = tmp.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
			if (board[ny][nx] != 0) continue;
			board[ny][nx] = board[tmp.y][tmp.x]+1;
			enqueue(nx, ny);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &l);
		scanf("%d %d", &xstart, &ystart);
		scanf("%d %d", &xend, &yend);
		bfs(xstart, ystart);
		printf("%d\n", board[yend][xend] - 1);
		front = 0; rear = 0;
		for (int a = 0; a < l; a++) {
			for (int b = 0; b < l; b++) {
				board[a][b] = 0;
			}
		}
	}
}