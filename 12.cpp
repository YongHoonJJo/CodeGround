#include <stdio.h>
#include <stdlib.h>

int safe(int r, int c, int n)
{
	return (0 <= r && r < n) && (0 <= c && c < n);
}

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int i, j, n;
		int r, c, ans=0;
		int **mirror;
		char **visited;
		enum {UP, DOWN, LEFT, RIGHT} cur;
		scanf("%d", &n);
		mirror = (int**)malloc(sizeof(int*)*n);
		visited = (char**)malloc(sizeof(char*)*n);

		for(i=0; i<n; i++) {
			mirror[i] = (int*)malloc(sizeof(int)*n);
			visited[i] = (char*)malloc(sizeof(char)*n);
		}
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				scanf("%1d", &mirror[i][j]);
				visited[i][j] = 0;
			}
		}
		// 1 /
		// 2 \
		
		cur = LEFT;
		r = c = 0;
		while(safe(r, c, n)) {
			if(!visited[r][c] && mirror[r][c]) {
				visited[r][c] = 1;
				ans++;
			}

			if(mirror[r][c] == 1) {
				switch(cur) {
					case UP: cur=RIGHT; c--; break;
					case DOWN: cur=LEFT; c++; break;
					case LEFT: cur=DOWN; r--; break;
					case RIGHT: cur=UP; r++; break;
				}
			}
			else if(mirror[r][c] == 2) {
				switch(cur) {
					case UP: cur=LEFT; c++; break;
					case DOWN: cur=RIGHT; c--; break;
					case LEFT: cur=UP; r++; break;
					case RIGHT: cur=DOWN; r--; break;
				}
			}
			else {
				switch(cur) {
					case UP: r++; break;
					case DOWN: r--; break;
					case LEFT: c++; break;
					case RIGHT: c--; break;
				}
			}
		}

		printf("Case #%d\n", tc);
		printf("%d\n", ans);

		for(i=0; i<n; i++)
			free(mirror[i]);
		free(mirror);
	}

	return 0;
}
