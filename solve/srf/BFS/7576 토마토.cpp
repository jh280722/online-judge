#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

const int MAX = 1001;
const int INF = 2147400000;
int map1[MAX][MAX];
int dis[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans, cnt=-1;

queue<DATA> q;

void bfs() {
	while (!q.empty()) {
		bool flag = true;
		int qs = q.size();
		cnt++;
		while (qs--) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				if (nx <=0 || nx>n  || ny<=0 || ny>m ) continue;

				if (visit[nx][ny] == false && map1[nx][ny] == 0) {
					visit[nx][ny] = true; 
					map1[nx][ny] = 1;
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

	fill(&visit[0][0], &visit[0][0] + MAX * MAX, 0);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map1[i][j];
			if (map1[i][j] == 1) {
				q.push({ i,j });
				visit[i][j] = true;
			}
			else if (map1[i][j] == -1)
				visit[i][j] = true;
		}
	}
	bfs();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == false) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}