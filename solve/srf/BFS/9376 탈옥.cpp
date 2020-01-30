#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

const int MAX = 102;
const int INF = 2147400000;
char map1[MAX][MAX];
int dis[MAX][MAX];
int visit[MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;

void sumarr() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dis[i][j] += visit[i][j];
		}
	}
}

void bfs(DATA loc) {
	fill(&visit[0][0], &visit[0][0] + MAX * MAX, INF);
	deque<DATA> q;
	q.push_back(loc);
	visit[loc.x][loc.y] = 0;
	while (!q.empty()) {
		bool flag = false;
		int qs = q.size();
		while (qs--) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop_front();

			for (int i = 0; i < 4; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				if (nx <0 || nx>n +1 || ny<0 || ny>m +1) continue;

				if (map1[nx][ny] != '*') {
					if (map1[nx][ny] == '#') {
						if (visit[nx][ny] > visit[x][y] + 1) {
							visit[nx][ny] = visit[x][y] + 1;
							q.push_back({ nx,ny });
						}
					}
					else {
						if (visit[nx][ny] > visit[x][y]) {
							visit[nx][ny] = visit[x][y];
							q.push_front({ nx,ny });
						}
					}
				}
			}
		}
	}
	sumarr();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		DATA loc[2];
		cin >> n >> m;
		int idx = 0;
		fill(&map1[0][0], &map1[0][0] + MAX * MAX, '.');
		memset(dis, 0, sizeof(dis));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map1[i][j];
				if (map1[i][j] == '$') {
					loc[idx].x = i;
					loc[idx++].y = j;
				}
			}
		}
		bfs(loc[0]);
		bfs(loc[1]);
		bfs({ 0,0 });
		ans = INF;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if(map1[i][j]=='#')
					ans = ans < dis[i][j] - 2 ? ans : dis[i][j] - 2;
				else
					ans = ans < dis[i][j] ? ans : dis[i][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}