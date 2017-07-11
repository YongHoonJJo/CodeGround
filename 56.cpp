#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int k;
		scanf("%d", &k);
		k++;

		stack<long long> S;
		printf("Case #%d\n", tc);
		while(k!=1) {
			S.push(k%2?7:4);
			k/=2;
		}
		while(!S.empty()) {
			printf("%lld", S.top());
			S.pop();
		}
		puts("");
	}
}
