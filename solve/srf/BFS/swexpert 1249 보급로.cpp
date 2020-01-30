#include <bits/stdc++.h>
#define MAX 101
#define INF 214700000
typedef long long ll;
using namespace std;

int n, t, ans;
char a[MAX][MAX];
int dis[MAX][MAX];

struct DATA {
	int r, c;
	int cnt;
};

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		fill(dis[0], dis[0] + MAX * MAX, INF);
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		queue<DATA> q;
		q.push({ 0,0,0 });
		dis[0][0] = 0;
		int cnt = 0;
		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int ncnt = q.front().cnt;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

				if (dis[nr][nc] > dis[r][c] + a[nr][nc] - '0') {
					q.push({ nr,nc,ncnt });
					dis[nr][nc] = dis[r][c] + a[nr][nc] - '0';
				}
			}
		}
		cout << '#' << tc + 1 << ' ' << dis[n - 1][n - 1] << '\n';
	}
	return 0;
}