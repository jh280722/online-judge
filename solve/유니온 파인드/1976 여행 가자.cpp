#include <iostream>
#include <string.h>
#include <queue>
#define MAX 201
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

int parent[201];
int rank_[201];

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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) {
				Union(i, j);
				Union(j, i);
			}
		}
	}
	int travel = 0;
	cin >> travel;
	travel = Find(travel);
	for (int i = 1; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (travel != Find(tmp)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES" << '\n';
	return 0;
}