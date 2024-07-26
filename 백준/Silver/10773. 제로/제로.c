int main() {

	int cnt,t=0,n,stack[100001],sum=0;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &n);
		if (n == 0) t--;
		else stack[t++] = n;
	}
	for (int i = 0; i < t; i++) {
		sum += stack[i];
	}
	printf("%d", sum);
}