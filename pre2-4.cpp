#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define INF	1e9
typedef pair<int, int> P;
typedef long long int lli;

vector<vector<P> > g;
vector<int> shelter, dist;
int n, m, k;

vector<int> dijkstra(int s)
{
	vector<int> dist(n+1, INF);
	vector<bool> visited(n+1, 0);
	priority_queue<P, vector<P>, greater<P> > pq;

	dist[s] = 0;
	pq.push(P(0, s));
	while(!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while(!pq.empty() && visited[cur]);

		if(visited[cur]) break;
		visited[cur] = 1;
		
		for(int i=0; i<g[cur].size(); i++) {
			int next = g[cur][i].first;
			int d = g[cur][i].second;
			
			if(dist[next] == dist[cur]+d && shelter[next]>shelter[cur]) {
				shelter[next] = shelter[cur];
			}

			if(dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push(P(dist[next], next));
				if(cur != s)
					shelter[next] = shelter[cur];
			}
		}
	}
	return dist;
}

int main()
{
	int tc, T;
	scanf("%d", &T);

	for(tc=1; tc<=T; tc++) {
		scanf("%d%d%d", &n, &m, &k);

		g = vector<vector<P> >(n+1);

		while(m--) {
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			g[a].push_back(P(b, w));
			g[b].push_back(P(a, w));
		}

		shelter = vector<int>(n+1, 0);
		while(k--) {
			int sh;
			scanf("%d", &sh);
			shelter[sh] = sh; // shelter[i] is the closest shelter from i
			g[0].push_back(P(sh, 0)); // g[0].size() means the number of shelters.
		}

		dist = dijkstra(0);
		
		lli sumD=0, sumV=0;
		for(int i=1; i<dist.size(); i++) {
			sumD += (lli)dist[i];
			sumV += (lli)shelter[i];
		}

		printf("Case #%d\n", tc);
		printf("%lld\n%lld\n", sumD, sumV);
	}

	return 0;
}
