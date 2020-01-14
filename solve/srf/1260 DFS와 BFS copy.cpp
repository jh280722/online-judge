#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool check[1001];
vector<int> a[1001];
void DFS(int v) {
	cout << v << ' ';
	check[v] = true;
	for (int i = 0; i < a[v].size(); i++) {
		if (check[a[v][i]]==false)
		{
			DFS(a[v][i]);
		}
	}
}
void BFS(int v) {
	memset(check, false, sizeof(check));
	queue<int> q;
	q.push(v);
	check[v] = true;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			if (check[a[x][i]] == false)
			{
				q.push(a[x][i]);
				check[a[x][i]] = true;
			}
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m,v;
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	DFS(v);
	cout << '\n';
	BFS(v);
	return 0;
}