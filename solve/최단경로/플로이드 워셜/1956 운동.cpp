#include <iostream>
#include <string.h>
#include <queue>
#define MAX 401
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

int dis[MAX][MAX];
void floyWarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] == INF || dis[k][j]==INF) continue;
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int worm;
	cin >> n >> m;
	fill(&dis[0][0], &dis[0][0] + MAX * MAX, INF);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = w;
	}
	floyWarshall();
	int m = INF;
	for (int i = 1; i <= n; i++) {
		m = min(m, dis[i][i]);
	}
	cout << (m == INF ? -1 : m);
	return 0;
}