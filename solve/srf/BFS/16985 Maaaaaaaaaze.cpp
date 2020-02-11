#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 5
#define INF 1000000000
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
	int z;
};
int n, m, t, k;
int ans;
int map[MAX][MAX][MAX];
int tmp[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
bool ch[5];
int dr[] = { -1,1,0,0, 0, 0 };
int dc[] = { 0,0,-1,1, 0, 0 };
int dz[] = { 0,0,0,0, 1, -1 };

int bfs() {
	queue<DATA> q;
	q.push({ 0,0,0 });
	memset(visit, 0, sizeof(visit));
	visit[0][0][0] = true;
	int lev = 0;
	while (!q.empty()) {
		bool flag = false;
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			int z = q.front().z;
			q.pop();
			if (r == MAX - 1 && c == MAX - 1 && z == MAX - 1) {
				return lev;
			}
			for (int k = 0; k < 6; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				int nz = z + dz[k];
				if (nr < 0 || nr >= MAX || nc < 0 || nc >= MAX || nz < 0 || nz >= MAX) continue;
				if (!tmp[nz][nr][nc] || visit[nz][nr][nc]) continue;
				visit[nz][nr][nc] = true;
				q.push({ nr,nc,nz });
			}

		}
		lev++;
	}
	return INF;
}
void rotate(int map[][5]) {
	int tmp[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map[i][j] = tmp[4 - j][i];
		}
	}
}
void dfs(int cnt) {
	if (cnt == 5) {
		if (tmp[4][4][4] == 1)
			ans = min(ans, bfs());
		return;
	}

	for (int i = 0; i < MAX; i++) {
		if (ch[i]) continue;
		ch[i] = true;
		memcpy(tmp[cnt], map[i], sizeof(map[i]));
		for (int j = 0; j < 4; j++) {
			rotate(tmp[cnt]);
			if (cnt == 0 && tmp[0][0][0] == 0) continue;
			dfs(cnt + 1);
            if(ans==12)
                return;
		}
		ch[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(map, 0, sizeof(map));
	ans = INF;

	for (int k = 0; k < MAX; k++) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> map[k][i][j];
			}
		}
	}

	dfs(0);
	if (ans == INF)
		ans = -1;
	cout << ans << '\n';

	return 0;
}