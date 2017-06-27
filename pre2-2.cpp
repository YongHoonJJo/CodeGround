#include <stdio.h>
#include <string.h>

#define MOD 1000000009

int v[50001], d[50001][101];

/*
int go(int n, int& k, int prev)
{
	int ans = 0;
	if(n < 0 || v[n]) return 0;
	if(d[n][prev]) return d[n][prev];
	if(n == 0) return 1;

	for(int i=k; i>=1; i--) {
		if(i != prev) {
			ans += go(n-i, k, i);
			ans %= MOD;
		}
	}
	return d[n][prev] = ans;
}
*/

int main()
{
	int T, tc;
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int n, k, l;
		int cur, jump;
		scanf("%d%d%d", &n, &k, &l);
	
		memset(v, 0, sizeof(v));
		memset(d, 0, sizeof(d));
		while(l--) {
			int b;
			scanf("%d", &b);
			v[b] = 1;	
		}

		for(jump=1; jump<=k; jump++)
			if(!v[jump])
				d[jump][jump] = 1;

		for(cur=1; cur<=n; cur++) {
			for(jump=1; jump<=k; jump++) {
				d[cur][0] += d[cur][jump];
				d[cur][0] %= MOD;
			}

			for(jump=1; jump<=k; jump++) {
				int next = cur+jump;
				if(next > n) break;
				if(!v[next]) {
					d[next][jump] += (d[cur][0]-d[cur][jump]+MOD);
					d[next][jump] %= MOD;
				}
			}
		}

		printf("Case #%d\n", tc);
		printf("%d\n", d[n][0]);
		//printf("%d\n", go(n, k, 0));
	}
}

