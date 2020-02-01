#include <iostream>
#include <queue>
#define ll long long
using namespace std;

struct DATA {
	int r, c;
	int dir;
};

const int MAX = 51;
const int INF = 2147400000;
int map[MAX][MAX];

//0 up 1 right 2 down 3 left
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;

queue<DATA> q;

int bfs() {
	int cnt = 1;
	while (!q.empty()) {
		bool flag = false;
		int r = q.front().r;
		int c = q.front().c;
		int dir = q.front().dir;
		q.pop();
		for (int i = 0; i < 4; i++) {
			dir = dir - 1 >= 0 ? dir - 1 : 3;
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 2)
				continue;
			if (map[nr][nc] == 0) {
				map[nr][nc] = 2;
				cnt++;
				q.push({ nr, nc, dir });
				flag = true;
				break;
			}
		}
		if (!flag) {
			int nr = r + dr[(dir + 2) % 4];
			int nc = c + dc[(dir + 2) % 4];
			if (map[nr][nc] == 1) {
				return cnt;
			}
			else {
				q.push({ nr, nc, dir });
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	q.push({ r,c,d });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	map[r][c] = 2;
	ans = bfs();
	cout << ans << '\n';
	return 0;
}