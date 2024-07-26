#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10001
int stack[MAX];
int t = -1;

void push(int x) {
	stack[++t] = x;
}

void pop() {
	if (t == -1) printf("-1\n");
	else printf("%d\n",stack[t--]);
}

void top() {
	if (t == -1) printf("-1\n");
	else printf("%d\n", stack[t]);
}

void size() {
	printf("%d\n", t+1);
}
void empty() {
	if (t == -1) printf("1\n");
	else printf("0\n");
}

int main() {
	char take[100];
	int cnt,n;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%s", take);
		if (strcmp(take, "push")==0) {
			scanf("%d", &n);
			push(n);
		}
		else if (strcmp(take, "pop")==0) pop();
		else if (strcmp(take, "top")==0) top();
		else if (strcmp(take, "size")==0) size();
		else if (strcmp(take, "empty")==0) empty();
	}
}


