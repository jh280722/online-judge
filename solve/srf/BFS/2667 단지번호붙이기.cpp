#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

const int MAX = 26;
const int INF = 2147400000;
char map1[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, h, p, k, l, ans, cnt;

queue<DATA> q;

int bfs(int x, int y) {
	int cnt = 1;
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

				if (visit[nx][ny]== false && map1[nx][ny] == '1') {
					visit[nx][ny] = true;
					cnt++;
					q.push({ nx,ny });
				}
			}
		}
	}
	return cnt;
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

	int apart[MAX * MAX];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j]==false && map1[i][j] == '1') {
				apart[cnt++]=bfs(i, j);
			}
		}
	}
	sort(apart, apart + cnt);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << apart[i] << '\n';
	}
	return 0;
}