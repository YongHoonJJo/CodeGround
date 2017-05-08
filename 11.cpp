#include <stdio.h>
#include <stdlib.h>

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int i, n, k;
		int *gap;
		int cur=0, ans=0;
		
		scanf("%d", &n);
		gap = (int*)malloc(sizeof(int)*(n+1));;
		gap[0] = 0;
		for(i=1; i<=n; i++) 
			scanf("%d", gap+i);
		scanf("%d", &k);

		i=1;
		while(i <= n) {
			if(gap[i]-gap[cur] <= k)
				i++;
			else {
				cur = i-1;
				ans++;
				if(gap[i]-gap[cur] > k) {
					ans = -1;
					break;
				}
			}
		}

		if(gap[n]-gap[cur] <= k) ans++;
		else ans=-1;

		printf("Case #%d\n%d\n", tc, ans);
	}

	return 0;
}
