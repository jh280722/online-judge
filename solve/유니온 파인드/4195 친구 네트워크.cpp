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
int fsize[MAX];

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
		fsize[u] += fsize[v];
	}
	else {
		parent[u] = v;
		rank_[u]++;
		fsize[v] += fsize[u];
	}
	return true;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		unordered_map <string, int> fd;
		int idx = 1;
		cin >> n;
		for (int i = 1; i < MAX; i++) {
			parent[i] = i;
			rank_[i] = 0;
			fsize[i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			string a, b;
			cin >> a >> b;
			if (fd[a] == 0) {
				fd[a] = idx++;
			}
			if (fd[b] == 0) {
				fd[b] = idx++;
			}
			Union(fd[a], fd[b]);
			cout << fsize[Find(fd[a])] << '\n';
		}
	}
	return 0;
}