#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 51
#define INF 1000000000
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
};
int n, m, t, k;
int ans;
int map[MAX][MAX];
int visit[MAX][MAX];
bool virus[10];

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

vector<DATA> v;
queue<DATA> q;
int zero;
int bfs() {
	memset(visit, 0, sizeof(visit));
	int cnt = zero;
	int lev = 0;
	while (!q.empty()) {
		bool flag = false;
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				if (visit[nr][nc] || map[nr][nc] == 1) continue;
				if (map[nr][nc] == 0) {
					cnt--;
				}
				visit[nr][nc] = true;
				q.push({ nr,nc });
			}

		}
		lev++;
		if (cnt == 0)
			return lev;
	}
	return INF;
}

void dfs(int idx, int cnt) {
	if (cnt == k) {
		for (int i = 0; i < v.size(); i++) {
			if (virus[i])
				visit[v[i].r][v[i].c] = true, q.push(v[i]);
		}
		ans = min(ans, bfs());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 3)
					map[i][j] = 0;
			}
		}
		while (!q.empty())
			q.pop();
		return;
	}

	for (int i = idx + 1; i < v.size(); i++) {
		virus[i] = true;
		dfs(i, cnt + 1);
		virus[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ans = INF;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
			else if (map[i][j] == 0)
				zero++;
		}
	}
	if (zero==0) {
		cout << 0 << '\n';
		return 0;
	}
	dfs(-1, 0);

	if (ans == INF)
		ans = -1;
	cout << ans << '\n';

	return 0;
}