#include <bits/stdc++.h>

#define MAX 102
#define INF 2147000000
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

char map1[MAX][MAX];
bool visit[MAX][MAX];
bool alp[26];

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;

void bfs() {
	queue<DATA> q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dr[i];
			int ny = y + dc[i];
			if (nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1) continue;
			if (map1[nx][ny] == '*' || visit[nx][ny]) continue;
			if (map1[nx][ny] >= 'A' && map1[nx][ny] <= 'Z') continue;

			if (map1[nx][ny] == '$') {
				map1[nx][ny] = '.';
				ans++;
			}

			if (map1[nx][ny] >= 'a' && map1[nx][ny] <= 'z' && !alp[map1[nx][ny] - 'a']) {
				alp[map1[nx][ny] - 'a'] = true;
				char d = map1[nx][ny] - 32;
				map1[nx][ny] = '.';
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if (map1[i][j] == d)
							map1[i][j] = '.';
					}
				}
				memset(visit, false, sizeof(visit));
				while (!q.empty()) q.pop();
			}
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		fill(&map1[0][0], &map1[0][0] + MAX * MAX, '.');
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map1[i][j];
			}
		}
		string s;
		cin >> s;
		for (auto c : s) {
			if (c == '0')
				break;
			alp[c - 'a'] = true;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map1[i][j] < 'A' || 'Z' < map1[i][j]) continue;
				if (alp[map1[i][j] - 'A']) map1[i][j] = '.';
			}
		}

		bfs();

		cout << ans << '\n';
		memset(visit, false, sizeof(visit));
		memset(alp, false, sizeof(alp));
	}

	return 0;
}