#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 214700000
typedef long long ll;
using namespace std;

struct GP {
	int v;
	int w;
};
int n, m, t, a, ans;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

vector<GP> graph[501];
int dis[501];
bool bellman(int dis[501]) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dis[i] == INF) continue;
			int sz = graph[i].size();
			for (int j = 0; j < sz; j++) {
				int v = graph[i][j].v;
				int w = graph[i][j].w;
				if (dis[v] > dis[i] + w) {
					dis[v] = dis[i] + w;
					if (k == n)
						return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int worm;
		cin >> n >> m >> worm;
		for (int i = 2; i <= n; i++) {
			dis[i] = INF;
		}
		for (int i = 1; i <= n; i++) 
			graph[i].clear();
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back({ v,w });
			graph[v].push_back({ u,w });
		}
		for (int i = 0; i < worm; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back({ v,-w });
		}
		if (!bellman(dis)) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}