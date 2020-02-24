#include <iostream>
#include <string.h>
#include <queue>
#define MAX 501
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

struct GP {
	int u, v, w;
};
vector<GP> gp[1001];
int dis[1001];
int path[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		gp[u].push_back({ u,v,w });
	}
	int st, dst;
	cin >> st >> dst;
	fill(&dis[0], &dis[0] + 1001, INF);
	dis[st] = 0;
	priority_queue<pii> pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int U = pq.top().second;
		int W = -pq.top().first;
		pq.pop();
		if (dis[U] < W) continue;
		for (int i = 0; i < gp[U].size(); i++) {
			int u = gp[U][i].u;
			int v = gp[U][i].v;
			int w = gp[U][i].w;
			if(dis[v]>W+w){
				dis[v] = W + w;
				path[v] = u;
				pq.push({ -dis[v],v });
			}
		}
	}
	cout << dis[dst] << '\n';
	int cnt = 2;
	int tmp = dst;
	vector<int> p;
	p.push_back(dst);
	while (path[tmp] != st) {
		p.push_back(path[tmp]);
		tmp = path[tmp];
		cnt++;
	}
	p.push_back(st);
	cout << cnt << '\n';
	for (int i = p.size()-1; i >= 0; i--) {
		cout << p[i]<<' ';
	}
	return 0;
}