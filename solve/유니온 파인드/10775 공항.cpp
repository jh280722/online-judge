#include <iostream>
#include <string.h>
#include <queue>
#include <unordered_map>
#define MAX 100001
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

int parent[MAX];
int rank_[MAX];

int Find(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = Find(parent[v]);
}

bool Union(int u, int v) {
	u = Find(u);
	v = Find(v);
	if (u == v)
		return false;
	if (rank_[u] > rank_[v]) {
		parent[v] = u;
		rank_[v]++;
	}
	else {
		parent[u] = v;
		rank_[u]++;
	}
	return true;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		rank_[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int p;
		cin >> p;
		p = Find(p);
		if (p == 0)
			break;
		Union(p, p-1);
		ans++;
	}
	cout << ans << '\n';
	return 0;
}