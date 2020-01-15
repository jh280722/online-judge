#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

const int MAX = 101;
const int INF = 2147000000;
char map1[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;
queue<DATA> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map1[i][j];
			if (map1[i][j] == '*') {
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map1[i][j] == 'S') {
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
	int lev = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			if (map1[x][y] == 'D') {
				cout << lev << '\n';
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				if (nx <1 || nx>n || ny<1 || ny>m) continue;
				if (visit[nx][ny] == false && map1[nx][ny] != 'X') {
					if (map1[x][y] == '*' && (map1[nx][ny] == '.' || map1[nx][ny] == 'S')) {
						visit[nx][ny] = true;
						map1[nx][ny] = '*';
						q.push({ nx,ny });
					}
					else if (map1[x][y] != '*' && (map1[nx][ny] == '.' || map1[nx][ny] == 'D')) {
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		lev++;
	}
	cout << "KAKTUS\n";
	return 0;
}