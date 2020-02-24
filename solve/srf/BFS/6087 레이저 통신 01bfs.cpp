#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans = INF;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
char map[MAX][MAX];
int vis[MAX][MAX];
struct DATA {
	int w;
	int r, c;
	int dir;
	bool operator()(DATA a, DATA b) {
		return a.w > b.w;
	}
};
deque<DATA> dq;
int dst[2];
void bfs() {
	fill(&vis[0][0], &vis[0][0] + MAX * MAX, INF);
	while (!dq.empty()) {
		int r = dq.front().r;
		int c = dq.front().c;
		int w = dq.front().w;
		int dir = dq.front().dir;
		if (r == dst[0] && c == dst[1]) {
			ans = min(ans, w);
		}
		dq.pop_front();
		for (int k = 0; k < 4; k++) {
			if (dir != -1 && k == (dir + 2) % 4) continue;
			int nr = r + dr[k];
			int nc = c + dc[k];
			int nw = w + 1;
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (map[nr][nc] == '*') continue;
			if (k == dir) {
				nw--;
				if (vis[nr][nc] < nw) continue;
				vis[nr][nc] = nw;
				dq.push_front({ nw,nr,nc,k });
			}
			else {
				if (vis[nr][nc] < nw) continue;
				vis[nr][nc] = nw;
				dq.push_back({ nw,nr,nc,k });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	bool la = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (!la && map[i][j] == 'C') {
				la = true;
				dq.push_back({ -1,i,j,-1 });
				vis[i][j] = 0;
			}
			if (la && map[i][j] == 'C') {
				dst[0] = i, dst[1] = j;
			}
		}
	}
	bfs();

	cout << ans << '\n';
	return 0;
}