#include <stdio.h>
#include <string.h>

int d[10001];
int p[10001], q[10001];

int go(int n)
{
	int a, b, c=0;
	if(n < 1) return 0;
	if(d[n]) return d[n];
	if(n == 1) {
		return p[1] > q[1] ? p[1] : q[1];
	}

	a = go(n-1) + p[n]; 
	b = go(n-2) + q[n];

	return d[n] = a > b ? a : b;
}

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int i, n;
		scanf("%d", &n);

		memset(d, 0, sizeof(d));
		for(i=1; i<=n; i++)
			scanf("%d", p+i);

		for(i=1; i<=n; i++)
			scanf("%d", q+i);

		printf("Case #%d\n", tc);
		printf("%d\n", go(n));
	}

	return 0;
}
