#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	char x, y;
	char z;
};

const int MAX = 101;
const int INF = 2147400000;
char map1[MAX][MAX][MAX];

int dr[] = { -1, 0, 1, 0, 0, 0 };
int dc[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int t;
int n, m, h, p, k, l, ans, cnt = -1;

queue<DATA> q;

int totalnum;
int tomato;
void bfs() {
	while (!q.empty()) {
		bool flag = true;
		int qs = q.size();
		cnt++;
		while (qs--) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				int nz = z + dz[i];
				if (nx <= 0 || nx > n || ny <= 0 || ny > m || nz <= 0 || nz > h) continue;

				if (map1[nx][ny][nz] == '0') {
					tomato++;
					map1[nx][ny][nz] = '1';
					q.push({ nx,ny, nz });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h; totalnum = m * n * h;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map1[i][j][k];
				if (map1[i][j][k] == '1') {
					q.push({ i,j,k });
					tomato++;
				}
				else if (map1[i][j][k] == '-') {
					char s;
					cin >> s;
					totalnum--;
				}
			}
		}
	}
	while (!q.empty()) {
		bool flag = true;
		int qs = q.size();
		cnt++;
		while (qs--) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				int nz = z + dz[i];
				if (nx <= 0 || nx > n || ny <= 0 || ny > m || nz <= 0 || nz > h) continue;

				if (map1[nx][ny][nz] == '0') {
					tomato++;
					map1[nx][ny][nz] = '1';
					q.push({ nx,ny, nz });
				}
			}
		}
	}

	if (totalnum != tomato) {
		cout << "-1\n";
		return 0;
	}
	cout << cnt << '\n';
	return 0;
}