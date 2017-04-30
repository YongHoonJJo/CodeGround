#include <stdio.h>

int g[201][201]={0};
int visited[201]={0};
int ok;

void dfs(int s, int n, int ck)
{
	int i;
	if(ok) {
	visited[s] = ck;

	for(i=1; i<=n; i++)
		if(g[s][i]) {
			if(!visited[i])
				dfs(i, n, -ck);
			else if(visited[i] == ck) {
				ok = 0;
				break;
			}
		}
	}
}

int main()
{
	int tc, T;
	scanf("%d\n", &T);

	for(tc=1; tc<=T; tc++) {
		int i, j, n, l;
		scanf("%d %d", &n, &l);
		
		for(i=0; i<=n; i++) {
			for(j=0; j<=n; j++)
				g[i][j] = 0;
			visited[i]=0;
		}
		ok = 1;
		
		while(l--) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a][b] = g[b][a] = 1;
		}
		
		dfs(1, n, 1);
		printf("Case #%d\n", tc);
		printf("%d\n", ok);
	}

	return 0;
}
