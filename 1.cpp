#include <stdio.h>

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int n, ans=0;
		scanf("%d", &n);
		
		while(n--) {
			int k;
			scanf("%d", &k);
			ans ^= k;
		}

		printf("Case #%d\n", tc);
		printf("%d\n", ans);
	}
	return 0;
}
