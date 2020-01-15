#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
	int cnt;
	DATA(int x, int y, int cnt) {
		this->x = x;
		this->y = y;
		this->cnt = cnt;
	}
	DATA() {
	}
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
		}
	}
	q.push({ 1,1,1 });
	visit[1][1] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt1 = q.front().cnt;
		q.pop();
		if (x == n && y == m) {
			cout << cnt1 << '\n';
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dr[i];
			int ny = y + dc[i];
			if (nx <1 || nx>n || ny<1 || ny>m) continue;
			if (visit[nx][ny] == false && map1[nx][ny] == '1') {
				visit[nx][ny] = true;
				q.push({ nx,ny,cnt1 + 1 });
			}
		}
	}

	return 0;
}