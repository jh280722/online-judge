#include <iostream>
#include <string.h>
#include <queue>
#define MAX 501
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

struct GP {
	int v;
	int c, d;
};
int n, m, k, t, a, ans;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

vector<GP> graph[MAX];
int dis[MAX][10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		priority_queue<pair<int, pii>> pq;
		fill(&dis[0][0], &dis[0][0] + MAX * 10001, INF);
		for (int i = 1; i <= n; i++)
			graph[i].clear();
		for (int i = 0; i < k; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			graph[u].push_back({ v,c,d });
		}
		int MIN = INF;
		dis[1][0] = 0;
		pq.push({ 0,{1,0} });
		while (!pq.empty()) {
			int d1 = -pq.top().first;
			int u = pq.top().second.first;
			int cost = pq.top().second.second;
			if (u == n) {
				MIN = d1;
				break;
			}
			pq.pop();
			if (dis[u][cost] < d1) continue;
			int sz = graph[u].size();
			for (int j = 0; j < sz; j++) {
				int v = graph[u][j].v;
				int c = graph[u][j].c;
				int d2 = graph[u][j].d;
				if (cost + c > m) continue;
				if (dis[v][cost + c] > d1 + d2) {
					for (int i = cost + c; i <= m; i++) {
						if (dis[v][i] > d1 + d2)
							dis[v][i] = d1 + d2;
						else 
							break;
					}
					pq.push({ -(d1 + d2) ,{v,cost + c} });
				}
			}
		}

		if (MIN == INF)
			cout << "Poor KCM\n";
		else
			cout << MIN << '\n';
	}
	return 0;
}