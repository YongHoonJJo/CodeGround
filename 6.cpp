#include <stdio.h>

int abs(int x)
{
	return x > 0 ? x : -x;
}

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		char ch;
		int i, n, k;
		int r, c, idx;
		int arr[200001]={0};
		long long ans=0LL;
		scanf("%d%d", &n, &k);

		// index는 좌표의 합, 그 곳에서의 최대값
		for(i=1; i<=n; i++)
			arr[i+1] = arr[i]+i;
		for(i=1; i<n; i++)
			arr[n+i+1] = arr[n+i]+n-i;
			
		ans = r = c = 1;
		for(i=0; i<k; i++) {	
			scanf(" %c", &ch);
			switch(ch)
			{
				case 'D': r++; break;
				case 'U': r--; break;
				case 'R': c++; break;
				case 'L': c--; break;
			}
			idx = r+c;
			
			if(idx <= n+1) {
				int tmp = idx&1 ? r : c; 
				ans += (arr[idx]-abs(idx-1-tmp)); 
			}
			else {
				int tmp = idx&1 ? c : r;
				ans += (arr[idx]-abs(idx-n-tmp));
			}
		}
		printf("Case #%d\n", tc);
		printf("%lld\n", ans);
	}

	return 0;
}
