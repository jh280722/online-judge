#include <bits/stdc++.h>
#define MAX 51
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int ans;
int Map[MAX][MAX];
bool vis[MAX][MAX];
queue<pii> q;
int sel[11];
void bfs() {
	int time = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			f(k, 0, 4) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc]) continue;
				if (Map[nr][nc] == 1) continue;
				vis[nr][nc] = true;
				q.push({ nr,nc });
			}
		}
		time++;
	}
	f(i, 0, n) {
		f(j, 0, n) {
			if (!vis[i][j] && Map[i][j] != 1)
				return;
		}
	}
	ans = min(ans, time-1);
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		f(i, 0, m) {
			vis[sel[i] / n][sel[i] % n] = true;
			q.push({ sel[i] / n,sel[i] % n });
		}
		bfs();
		memset(vis, 0, sizeof vis);
		return;
	}
	f(i, idx, n * n) {
		int r = i / n;
		int c = i % n;
		if (Map[r][c] != 2) continue;
		sel[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	f(i, 0, n) {
		f(j, 0, n) {
			cin >> Map[i][j];
		}
	}
	ans = INF;
	dfs(0, 0);
	if (ans == INF)
		ans = -1;
	cout << ans;
	return 0;
}
