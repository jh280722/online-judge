#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF 2147000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, t;

vi fr[MAX];
bool vis[2][MAX];
void bfs(int type, int idx) {
	queue<int> q;
	q.push({ idx });
	vis[type][idx] = true;
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		f(k, fr[idx].size()) {
			if (vis[type][fr[idx][k]]) continue;
			q.push({ fr[idx][k] });
			vis[type][fr[idx][k]] = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<pii> edge(m);
	f(i, m) {
		cin >> edge[i].first >> edge[i].second;
		fr[edge[i].first].push_back(edge[i].second);
	}
	cin >> t;
	bfs(0, 1);
	f(i, n)
		fr[i].clear();
	f(i, m) {
		fr[edge[i].second].push_back(edge[i].first);
	}
	bfs(1, n);
	while (t--) {
		int a;
		cin >> a;
		if (vis[0][a] && vis[1][a])
			cout << "Defend the CTP\n";
		else
			cout << "Destroyed the CTP\n";
	}

	return 0;
}