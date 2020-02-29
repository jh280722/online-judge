#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 11
#define INF 2147000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

int ans = INF;
int total;
int pol[MAX];
bool vis[MAX][MAX];
bool tmp[MAX][MAX];
bool sel[MAX];

bool bfs(int idx, bool type) {
	memcpy(vis, tmp, sizeof(tmp));
	queue<int> q;
	vis[idx][idx] = true;
	f(i, n) {
		if (vis[idx][i + 1] && sel[i + 1] != type)
			q.push({ i + 1 });
	}
	while (!q.empty()) {
		int id = q.front();
		q.pop();
		f(i, n) {
			if (!vis[id][i + 1]) continue;
			if (vis[idx][i + 1]) continue;
			if (sel[i + 1] == type) continue;
			vis[idx][i + 1] = true;
			q.push({ i + 1 });
		}
	}
	f(i, n) {
		if (sel[i + 1] != type && !vis[idx][i + 1]) {
			return true;
		}
	}
	return false;
}

void dfs(int idx, int cnt) {
	if (cnt == n) {
		return;
	}

	if (cnt != 0) {
		bool flag = false;
		int s1 = 0, s2 = 0;
		f(i, n) {
			if (sel[i + 1]) {
				if (bfs(i + 1, false)) {
					flag = true;
					break;
				}
				s1 += pol[i + 1];
			}
			else {
				if (bfs(i + 1, true)) {
					flag = true;
					break;
				}
				s2 += pol[i + 1];
			}
		}
		if (!flag) {
			ans = min(ans, abs(s1 - s2));
		}
	}

	for (int i = idx; i <= n; i++) {
		sel[i] = true;
		dfs(i + 1, cnt + 1);
		sel[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	f(i, n) {
		cin >> pol[i + 1];
		total += pol[i + 1];
	}
	f(i, n) {
		int a;
		cin >> a;
		f(j, a) {
			int b;
			cin >> b;
			tmp[i + 1][b] = true;
		}
	}

	dfs(1, 0);
	if (ans == INF) 
		ans = -1;
	cout << ans;
	return 0;
}