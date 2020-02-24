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
#define MAX 101
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

vector<node> grape[801];
int dis[3][801];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	fill(&dis[0][0], &dis[0][0] + 801*3, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		grape[u].push_back({ v,w });
		grape[v].push_back({ u,w });
	}
	int s = 0, d = 0;
	cin >> s >> d;
	for (int k = 0; k < 3; k++) {
		int st = 1;
		if (k == 1)
			st = s;
		else if (k == 2)
			st = d;
		dis[k][st] = 0;
		pq.push({ 0,st });
		while (!pq.empty()) {
			int w = pq.top().first;
			int v = pq.top().second;
			pq.pop();
			if (dis[k][v] < w) continue;
			for (int i = 0; i < grape[v].size(); i++) {
				if (dis[k][grape[v][i].v] > w + grape[v][i].w) {
					dis[k][grape[v][i].v] = w + grape[v][i].w;
					pq.push({ dis[k][grape[v][i].v],grape[v][i].v });
				}
			}
		}
	}
	ans = min((dis[0][s] + dis[1][d] + dis[2][n]), 
		(dis[0][d] + dis[2][s] + dis[1][n]));

	if (ans>=INF)
		cout << "-1" << '\n';
	else {
		cout << ans << '\n';
	}

	return 0;
}