#include <stdio.h>
#include <stdlib.h>
#define MAXN	300001

int cmp(const void *u, const void * v)
{
	return *(int*)u > *(int*)v ? 1 : -1;
}

int main(void) {
	int TC;
	int test_case;
	setbuf(stdout, NULL);

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) {
		int i, n;
		int arr[MAXN];
		int ans=0, max=0;
		scanf("%d", &n);
		
		for(i=0; i<n; i++) 
			scanf("%d", arr+i);

		qsort(arr, n, sizeof(int), cmp);

		for(i=0; i<n; i++) {
			if(max < arr[i]+n-i)
				max = arr[i]+n-i;
		}

		for(i=0; i<n; i++) {
			if(max <= arr[i]+n)
				ans++;
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;
}
