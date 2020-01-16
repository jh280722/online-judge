#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

const int MAX = 101;
const int INF = 2147400000;
char map1[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, h, p, k, l, ans, cnt;

queue<DATA> q;

void bfs(int x, int y, char c1, char c2) {
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				if (visit[nx][ny] == false && (map1[nx][ny] == c1 || map1[nx][ny] == c2)) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map1[i][j];
		}
	}

	int rg = 0, nrg = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				nrg++;
				bfs(i, j, map1[i][j], map1[i][j]);
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				rg++;
				if (map1[i][j] == 'B')
					bfs(i, j, 'B', 'B');
				else
					bfs(i, j, 'R', 'G');
			}
		}
	}
	cout << nrg << ' ' << rg;
	return 0;
}