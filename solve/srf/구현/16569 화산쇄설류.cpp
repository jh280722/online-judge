#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 101
#define INF 1000000000
using namespace std;
typedef long long ll;

struct DATA {
	int x, y;
	int t;
};

int n, m, v, t;
int map[MAX][MAX];
bool visit[MAX][MAX];
DATA val[5001];
int nowh, mint;
int maxh;

bool cmp(DATA a, DATA b) {
	return (a.t < b.t) ? 1 : 0;
}

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

queue<DATA> q;
void bfs(int r, int c) {
	nowh = map[r][c];
	visit[r][c] = true;
	q.push({ r,c,-1 });
	int lev = 0;
	bool flag = false;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int r = q.front().x;
			int c = q.front().y;
			int t = q.front().t;

			if (t == -1 && nowh == maxh) {
				flag = true;
				break;
			}

			if (t > lev) {
				q.push(q.front());
				q.pop();
				continue;
			}
			if (t == lev)
				visit[r][c] = true;
			if (t == -1 && nowh < map[r][c]) {
				nowh = map[r][c];
				mint = lev;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr <= 0 || nr > m || nc <= 0 || nc > n || visit[nr][nc]) continue;
				if (t == -1 && map[nr][nc] == -1) continue;
				visit[nr][nc] = true;
				q.push({ nr,nc ,t });
			}
		}
		lev++;
		if (flag)
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int stx, sty;
	cin >> m >> n >> v;
	cin >> stx >> sty;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			maxh = max(maxh, map[i][j]);
		}
	}
	for (int i = 0; i < v; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		val[i] = { x,y,t };
		q.push({ x,y,t });
		map[x][y] = -1;
	}
	sort(val, val + v, cmp);
	bfs(stx, sty);

	cout << nowh << ' ' << mint << '\n';

	return 0;
}
