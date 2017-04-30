#include <stdio.h>

#define MAXN	101
#define INF		1000000000

int main(void) {

	int T;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		int n, m, k;
		int p, s, e;
		int i, j, l, ans=0;
		int g[MAXN][MAXN];
		scanf("%d %d %d", &n, &m, &k);
		
		for(i=0; i<MAXN; i++) {
			for(j=0; j<MAXN; j++) {
				g[i][j] = INF;
			}
			g[i][i] = 0;
		}

		while(m--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[a][b] = g[b][a] = c;
		}

		for(l=1; l<=n; l++) {
			for(i=1; i<=n; i++) {
				for(j=1; j<=n; j++) {
					if(g[i][j] > g[i][l]+g[l][j])
						g[i][j] = g[i][l]+g[l][j];
				}
			}
		}
		
		scanf("%d", &p);
		while(p--) {
			scanf("%d %d", &s, &e);
			if(g[s][e] > k)
				ans++;
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}
	return 0;
}
