#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct P { int x, y; };

bool cmp(P a, P b)
{
	if(a.y == b.y) { 
		return a.x < b.x;
	}
	else
		return a.y > b.y;
}

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		int i, n, x, y;
		scanf("%d", &n);

		vector<P> v;
		for(i=0; i<n; i++) {
			scanf("%d%d", &x, &y);
			v.push_back((P){x, y} );
		}

		sort(v.begin(), v.end(), cmp);
		
		int Lidx=0;
		vector<int> lis;

		for(i=0; i<n; i++) {
			int k = v[i].x;
			if(!i) {
				lis.push_back(k);
			}
			else {
				if(lis[Lidx] <= k) {
					lis.push_back(k);
					Lidx++;
				}
				else {
					int pos = lower_bound(lis.begin(), lis.end(), k)-lis.begin();
					lis[pos] = k;
				}
			}
		}

		printf("Case #%d\n", tc);
		printf("%d\n", Lidx+1);
	}
	return 0;
}
