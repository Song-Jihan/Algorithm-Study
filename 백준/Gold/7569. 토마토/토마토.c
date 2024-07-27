#include<stdio.h>
#include<stdlib.h>
#define MAX 10002
int n, m, h,num, rear, front;
int dx[6] = { 0,0,0,1,0,-1 },dy[6]={1,-1,1,0,-1,0};
int max,arr[MAX][101];

typedef struct QueueType {
	int x, y;
}QueueType;

QueueType q[3000003];

void enqueue(int x, int y) {
	rear = (rear + 1) % 3000003;
	q[rear].y = y;	
	q[rear].x = x;
}

QueueType dequeue() {
	front = (front + 1) % 3000003;
	return q[front];
}

int main() {
	QueueType tmp;
	scanf("%d %d %d", &m,&n,&h);
	for (int a = 0; a < h; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < m; c++) {
				scanf("%d", &num);
				if (num == 1) {
					arr[b + a * n][c] = 1;
					enqueue(c, b + a * n);
				}
				else if (num == -1) {
					arr[b + a * n][c] = -1;
				}
			}
		}
	}

	int tx, ty, nx, ny;
	while (front < rear) {
		tmp = dequeue();
		tx = tmp.x; 
		ty = tmp.y;
		for (int i = 0; i < 6; i++) {
			nx = tx + dx[i];
			if (i <= 1) {
				ny = ty + (dy[i] * n);
			}
			else ny = ty + dy[i];
			if ((ny % n == n - 1 && ty % n == 0 || ny % n == 0 && ty % n == n - 1) && ny != ty) {
				continue;
			}
			if (nx < 0 || ny < 0 || nx >= m || ny >= n * h) continue;

			if (arr[ny][nx] != 0) continue;
			arr[ny][nx] = arr[ty][tx] + 1;
			if (arr[ny][nx] > max)
				max = arr[ny][nx];
			enqueue(nx, ny);
			/*
			printf("=======================\n");
			for (int i = 0; i < n * h; i++) {
				for (int j = 0; j < m; j++) {
					printf("%d ", arr[i][j]);
				}
				printf("\n");
			}*/
		}
	}
	

	for (int i = 0; i < n * h; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	if (max == 0) printf("0");
	else printf("%d", max - 1);
}
