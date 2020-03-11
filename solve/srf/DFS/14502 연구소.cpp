#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 9

int map[MAX][MAX];
int origin[MAX][MAX];
int n, m;
int ans;
struct DATA {
	int r, c;
};
queue<DATA> virus;
vector<DATA> blank;
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
int bfs() {
	int cnt = 0;
	queue<DATA> q = virus;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (map[nr][nc] == 0) {
			q.push({ nr,nc });
			map[nr][nc] = 2;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cnt++;
			}
			if (map[i][j] != 3)
				map[i][j] = origin[i][j];
		}
	}
	return cnt;
}
void dfs(int idx, int cnt) {
	if (cnt == 3) {
		ans=max(ans,bfs());
		return;
	}

	for (register int i = idx + 1; i < blank.size(); i++) {
		int r = blank[i].r, c = blank[i].c;
		map[r][c] = 3;
		dfs(i, cnt + 1);
		map[r][c] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			origin[i][j] = map[i][j];
			if (map[i][j] == 2)
				virus.push({ i,j });
			else if (map[i][j] == 0)
				blank.push_back({ i,j });
		}
	}

	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}