#include <stdio.h>
#define MAXN	100001

int main(void) {
	int T;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		int i, n, s, k;
		int pSum[MAXN]={0};
		int f=1, r=1, ans=MAXN;
		scanf("%d %d", &n, &s);

		for(i=1; i<=n; i++) {
			scanf("%d", &k);
			pSum[i] = pSum[i-1]+k;
		}

		while(f != n) {
			if(pSum[r]-pSum[f] < s) {
				r++;
				if(r > n) break;
			}
			else {
				int tmp = r-f;
				if(ans > tmp)
					ans = tmp;
				f++;
			}
		}
		if(ans == MAXN) ans=0;
		printf("#testcase%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;
}
