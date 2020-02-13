#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 11
#define INF 2147483647
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
	int dir;
};
int n, m, t, k;
int ans = 0;

int map[MAX][MAX];
bool vis[MAX][MAX];
int dr[] = { -1,0,0,1 };
int dc[] = { 0,-1,1,0 };
int cnt;
int root[7];

/* find(x): 재귀 이용 */
int Find(int x) {
	// 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
	if (root[x] == x) {
		return x;
	}
	else {
		// 각 노드의 부모 노드를 찾아 올라간다.
		return Find(root[x]);
	}
}
/* union(x, y) */
void Union(int x, int y) {
	// 각 원소가 속한 트리의 루트 노드를 찾는다.
	x = Find(x);
	y = Find(y);
	root[y] = x;
}

void bfs(int r, int c) {
	queue<DATA> q;
	q.push({ r, c });
	vis[r][c] = true;
	map[r][c] = cnt;
	bool flag = false;
	int lev = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k], nc = c + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc]) continue;
				if (map[nr][nc] == 0) continue;
				map[nr][nc] = cnt;
				q.push({ nr,nc });
				vis[nr][nc] = true;
			}
		}
		lev++;
	}
}

queue<DATA> island[7];
int connect[7][7];
int con_bfs(int isnum) {
	queue<DATA> q = island[isnum];
	int min = INF;
	int lev = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			int dir = q.front().dir;
			q.pop();
			if (dir == -1)
				for (int k = 0; k < 4; k++) {
					int nr = r + dr[k], nc = c + dc[k];
					if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
					int num = map[nr][nc];
					if (num == isnum) continue;
					if (num != 0) continue;
					q.push({ nr,nc,k });
				}
			else {
				int nr = r + dr[dir], nc = c + dc[dir];
				if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
				int num = map[nr][nc];
				if (connect[isnum][num] <= lev) continue;
				if (!(0 < num && num <= cnt)) {
					q.push({ nr,nc,dir });
				}
				else if (lev >= 2) {
					connect[isnum][num] = lev;
					connect[num][isnum] = lev;
				}

			}
		}
		lev++;
	}
	return min;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < 7; i++)
		root[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !vis[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i <= cnt; i++) {
		for (int j = 0; j <= cnt; j++) {
			connect[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				island[map[i][j]].push({ i,j ,-1 });
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
		con_bfs(i);
	//for (int i = 1; i <= cnt; i++) {
	//	for (int j = 1; j <= cnt; j++) {
	//		cout << connect[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	while (true) {
		bool flag = true;
		int ro = Find(1);
		for (int i = 2; i <= cnt; i++) {
			if (ro != Find(i)) {
				flag = false;
				break;
			}
		}
		if (flag)
			break;
		int min = INF, mini = 0, minj = 0;
		for (int i = 1; i <= cnt; i++) {
			for (int j = 1; j <= cnt; j++) {
				if (min > connect[i][j] && Find(i) != Find(j)) {
					min = connect[i][j];
					mini = i, minj = j;
				}
			}
		}
		if (min == INF) {
			ans = -1;
			break;
		}
		ans += min;
		Union(mini, minj);
	}
	if (ans == 0)
		ans = -1;
	cout << ans << '\n';
	return 0;
}