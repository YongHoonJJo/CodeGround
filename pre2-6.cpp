#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pos {
	int x, y;
};

struct Rec {
	Pos p1, p2;
};

Rec rect[5001];
int n, m, k;
int d[5001];

int dfs(int s)
{
	int ans=1;
	Rec ri = rect[s]; 
	if(d[s]) return d[s];

	for(int j=0; j<k; j++) {
		Rec rj = rect[j];
		if(j != s) {
			if((ri.p1.x <= rj.p1.x) && (rj.p1.x < rj.p2.x) && (rj.p2.x <= ri.p2.x)) {
				if((ri.p1.y <= rj.p1.y) && (rj.p1.y < rj.p2.y) && (rj.p2.y <= ri.p2.y)) { 
					ans = max(ans, dfs(j)+1);
				}
			}
		}
	}
	return d[s] = ans;
}


int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		scanf("%d%d%d", &n, &m, &k);

		for(int i=0; i<k; i++) {
			Rec &r = rect[i];
			scanf("%d%d%d%d", &r.p1.x, &r.p1.y, &r.p2.x, &r.p2.y);
		}

		int ans=0;
		memset(d, 0, sizeof(d));
		for(int i=0; i<k; i++) 
			ans = max(ans, dfs(i));

		printf("Case #%d\n", tc);
		printf("%d\n", ans);
	}
}
