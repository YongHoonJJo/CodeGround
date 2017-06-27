#include <cstdio>
#include <iostream>

using namespace std;

int map[101][101];
bool d[101];

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int tc, T;

	scanf("%d", &T);	
	for(tc=1; tc<=T; tc++) {
		int k, l, n, m;
		scanf("%d%d%d%d", &k, &l, &n, &m);

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				map[i][j] = false;
			d[i] = 0;
		}

		while(m--) {
			int a, b; 
			scanf("%d%d", &a, &b); 
			map[a][b] = map[b][a] = 1;
		}

		int N = n;
		while(true)
		{
			int i;
			for(i=1; i<=n; i++)
			{
				if(!d[i]) { // die
					int c = 0; // i의 간선 수 cnt
					for (int j=1; j<=n; j++) 
						c += map[i][j];

					if(c < k || c > N-l-1)
					{
						N--;
						d[i] = true;
						for(int j=1; j<=n; j++) 
							map[i][j] = map[j][i] = 0;
						break;
					}
				}
			}
			if (i == n+1) 
				break;
		}

		int ans=0;
		for (int i=1; i<=n; i++) 
			ans += d[i] ? i : 0;

		printf("Case #%d\n%d\n", tc, ans);

	}
	return 0;
}
