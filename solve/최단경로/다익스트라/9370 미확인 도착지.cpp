#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#include <set>
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define MAX 2001
#define INF 214748364
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };

struct node {
	int v, w;
};

vector<node> graph[MAX];
int origin_dis[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra(int dis[MAX], int st) {
	dis[st] = 0;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (dis[v] < w) continue;
		for (int i = 0; i < graph[v].size(); i++) {
			if (dis[graph[v][i].v] > w + graph[v][i].w) {
				dis[graph[v][i].v] = w + graph[v][i].w;
				pq.push({ dis[graph[v][i].v],graph[v][i].v });
			}
		}
	}
}

int dst[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		fill(&origin_dis[0], &origin_dis[0] + MAX, INF);
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		graph->clear();
		cin >> n >> m >> k;
		int s, g, h;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			w *= 2;
			if ((u == g && v == h) || (v == g && u == h)) {
				w--;
			}
			graph[u].push_back({ v,w });//양방향
			graph[v].push_back({ u,w });
		}
		for (int i = 0; i < k; i++) {
			cin >> dst[i]; //목적지
		}
		sort(dst, dst + k);
		dijkstra(origin_dis, s);

		for (int i = 0; i < k; i++) {
			if (origin_dis[dst[i]] == INF) continue;
			if (origin_dis[dst[i]] % 2 == 1)
				cout << dst[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}