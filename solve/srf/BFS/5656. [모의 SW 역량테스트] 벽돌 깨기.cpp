#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 16
#define INF 1000000000
typedef long long ll;
using namespace std;

struct POINT {
	int r, c;
	int cnt;
};
int n, m, t, k;
int ans;
int map[MAX][MAX];
int copy_map[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int seq[4];
void bfs(int ball_c) {
	memset(visit, 0, sizeof(visit));
	int r = 0, c = ball_c;
	for (int i = 0; i < n; i++) {
		if (copy_map[i][ball_c] != 0) {
			r = i;
			break;
		}
	}
	queue<POINT> q;
	q.push({ r,c ,copy_map[r][c] });
	copy_map[r][c] = 0;
	visit[r][c] = true;
	while (!q.empty()) {
		r = q.front().r;
		c = q.front().c;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt == 1)
			continue;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < cnt; j++) {
				int nr = r + dr[i] * j, nc = c + dc[i] * j;
				if (nr<0 || nr>=n || nc<0 || nc>=m || visit[nr][nc]) continue;
				if (copy_map[nr][nc] != 0) {
					q.push({ nr,nc,copy_map[nr][nc] });
					visit[nr][nc] = true;
					copy_map[nr][nc] = 0;
				}
			}
		}
	}
}
void fall() {
	for (int j = 0; j < m; j++) {
		int icnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (copy_map[i][j] >= 1) {
				copy_map[n - 1 - icnt][j] = copy_map[i][j];
				if (n - 1 - icnt != i) copy_map[i][j] = 0;
				icnt++;
			}
		}
	}
	/*
	queue<int> q;
	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (copy_map[i][j] != 0)
				q.push(copy_map[i][j]);
		}
		for (int i = n - 1; i >= 0; i--) {
			if (!q.empty()) {
				copy_map[i][j] = q.front();
				q.pop();
			}
			else
				copy_map[i][j] = 0;
		}
	}*/
}
void dfs(int cnt) {
	if (ans == 0)
		return;
	if (cnt == k) {
		memcpy(copy_map, map, sizeof(map));
		for (int i = 0; i < cnt; i++) {
			bfs(seq[i]);
			fall();
		}
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (copy_map[i][j] >= 1) cnt++;
				else if (copy_map[i][j] == 0) break;
			}
		}
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < m; i++) {
		seq[cnt] = i;
		dfs(cnt + 1);
		if (ans == 0)
			return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = INF;
		cin >> k >> m >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0);

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}