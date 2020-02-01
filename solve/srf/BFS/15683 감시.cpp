#include <iostream>
#include <queue>
#define ll long long
using namespace std;

struct DATA {
	int r, c;
	int type;
	int dir;
};

const int MAX = 9;
const int INF = 2147400000;
int map[MAX][MAX];
int visit[MAX][MAX];

//0 up 1 right 2 down 3 left
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans = 64;

int cctvn;
DATA cctv[9];
queue<DATA> q;

int bfs() {
	int cnt = 0;

	while (!q.empty()) {
		bool flag = false;
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			int type = q.front().type;
			int dir = q.front().dir;
			q.pop();

			bool f1 = true, f2 = true, f3 = true, f4 = true;
			switch (type) {
			case 1:
				for (int j = 1; j < 8; j++) {
					int nr = r + dr[dir] * j;
					int nc = c + dc[dir] * j;
					if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 6)
						break;
					if (map[nr][nc] == 0)
						map[nr][nc] = -1;//보이는 곳
				}
				break;
			case 2:
				for (int j = 1; j < 8; j++) {
					int nr, nc;
					if (f1) {
						nr = r + dr[dir] * j;
						nc = c + dc[dir] * j;
						if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 6) {
							f1 = false;
						}
						else if (map[nr][nc] == 0)
							map[nr][nc] = -1;//보이는 곳
					}
					if (f2) {
						nr = r + dr[(dir + 2) % 4] * j;
						nc = c + dc[(dir + 2) % 4] * j;
						if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 6)
							f2 = false;
						else if (map[nr][nc] == 0)
							map[nr][nc] = -1;//보이는 곳
					}
				}
				break;
			case 3:
				for (int j = 1; j < 8; j++) {
					int nr, nc;
					if (f1) {
						nr = r + dr[dir] * j;
						nc = c + dc[dir] * j;
						if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 6) {
							f1 = false;
						}
						else if (map[nr][nc] == 0)
							map[nr][nc] = -1;//보이는 곳
					}
					if (f2) {
						nr = r + dr[(dir + 1) % 4] * j;
						nc = c + dc[(dir + 1) % 4] * j;
						if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 6)
							f2 = false;
						else if (map[nr][nc] == 0)
							map[nr][nc] = -1;//보이는 곳
					}
				}
				break;
			case 4:
				for (int i = 0; i < 4; i++) {
					if (i == dir)continue;
					for (int j = 1; j < 8; j++) {
						int nr = r + dr[i] * j;
						int nc = c + dc[i] * j;
						if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 6)
							break;
						if (map[nr][nc] == 0)
							map[nr][nc] = -1;//보이는 곳
					}
				}
				break;
			case 5:
				for (int i = 0; i < 4; i++) {
					for (int j = 1; j < 8; j++) {
						int nr = r + dr[i] * j;
						int nc = c + dc[i] * j;
						if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 6)
							break;
						if (map[nr][nc] == 0)
							map[nr][nc] = -1;//보이는 곳
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cnt++;
			}
			if (map[i][j] == -1) {
				map[i][j] = 0;
			}
		}
	}
	return cnt;
}

void dfs(int idx, int cnt) {
	if (cnt == cctvn) {
		while (!q.empty())q.pop();
		for (int i = 0; i < cctvn; i++) {
			q.push(cctv[i]);
		}
		ans = min(ans, bfs());
		return;
	}

	for (int i = idx + 1; i < cctvn; i++) {
		for (int j = 0; j < 4; j++) {
			cctv[i].dir = j;
			dfs(i, cnt + 1);
			cctv[i].dir = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ans = 64;
	cin >> n >> m;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv[cctvn++] = { i,j, map[i][j],0 };
			}
		}
	}
	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}