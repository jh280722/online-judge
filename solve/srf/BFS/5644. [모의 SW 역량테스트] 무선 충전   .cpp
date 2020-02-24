#include <iostream>
#include <string.h>
#include <queue>
#define MAX 11
#define INF 214700000
typedef long long ll;
using namespace std;

int n, m, t, a, ans;
bool vis[MAX][MAX][9];

struct POINT {
	int r, c;
};

struct DATA {
	POINT u1, u2;
};
int dr[] = { 0, -1,0,1,0 };
int dc[] = { 0, 0,1,0,-1 };
int dir1[101];
int dir2[101];
int bc[9];

void bfs(int r,int c, int range,int num) {
	queue<POINT> q;
	q.push({ r,c });
	vis[r][c][num] = true;
	int time = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			q.pop();

			for (int k = 1; k < 5; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (nr < 1 || nr > 10 || nc < 1 || nc > 10 || vis[nr][nc][num]) continue;
				vis[nr][nc][num] = true;
				q.push({ nr,nc });
			}
		}
		time++;
		if (time >= range)
			break;
	}
}

POINT u[2];
bool charging[9];
void dfs(int cnt, int sum) {
	if (cnt == 2) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < a; i++) {
		if (vis[u[cnt].r][u[cnt].c][i]) {
			if(charging[i])
				dfs(cnt + 1, bc[i]);
			else {
				charging[i] = true;
				dfs(cnt + 1, sum + bc[i]);
				charging[i] = false;
			}
		}
	}
	dfs(cnt + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		u[0] = { 1,1 },u[1]= { 10,10 };
		ans = 0;
		cin >> m >> a;
		for (int i = 0; i < m; i++) {
			cin >> dir1[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> dir2[i];
		}
		for (int i = 0; i < a; i++) {
			int r, c, range;
			cin >> c >> r >> range >> bc[i];
			bfs(r,c,range,i);
		}
		for (int i = 0; i <= m; i++) {
			dfs(0, ans);
			u[0].r += dr[dir1[i]], u[0].c += dc[dir1[i]];
			u[1].r += dr[dir2[i]], u[1].c += dc[dir2[i]];
		}
		cout << '#' << tc << ' ' << ans << '\n';
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}