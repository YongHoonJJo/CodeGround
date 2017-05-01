#include <stdio.h>
#include <stdlib.h>

int cmp(const void *u, const void *v)
{
	return *(int*)u > *(int*)v ? -1 : 1;
}

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int i, n , k;
		int score[200000];
		int ans=0;
		scanf("%d %d", &n, &k);
		
		for(i=0; i<n; i++)
			scanf("%d", score+i);

		qsort(score, n, sizeof(int), cmp);

		for(i=0; i<k; i++)
			ans += score[i];


		printf("Case #%d\n", tc);
		printf("%d\n", ans);
	}

	return 0;
}
