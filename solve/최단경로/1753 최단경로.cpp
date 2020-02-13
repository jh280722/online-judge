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
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };

struct node {
	int v, w;
};

vector<node> grape[20001];
int dis[20001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	fill(&dis[0], &dis[0] + 20001, INF);
	priority_queue<pii,vector<pii>, greater<pii>> pq;
	int s = 0;
	cin >> s;
	dis[s] = 0;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		grape[u].push_back({ v,w });
	}
	pq.push({ 0,s});
	while (!pq.empty()) {
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		if (dis[v] < w) continue;
		for (int i = 0; i < grape[v].size(); i++) {
			if (dis[grape[v][i].v] > w + grape[v][i].w) {
				dis[grape[v][i].v] = w + grape[v][i].w;
				pq.push({ dis[grape[v][i].v],grape[v][i].v });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dis[i] << '\n';
	}

	return 0;
}