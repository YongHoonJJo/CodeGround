#include <cstdio>

void hanoi(int n, int from, int by, int to)
{
	if(n == 1) {
		printf("%d -> %d\n", from, to);
		return ;
	}
	hanoi(n-1, from, to, by);
	printf("%d -> %d\n", from, to);
	hanoi(n-1, by, from, to);
}

int main()
{
	int tc, T;
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d\n", tc);
		hanoi(n, 1, 2, 3);
	}

}
