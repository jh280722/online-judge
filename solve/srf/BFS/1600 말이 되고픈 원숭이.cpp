#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
	int k;
};

const int MAX = 201;
const int INF = 2147000000;
int map1[MAX][MAX];
bool visit[MAX][MAX][31];

int dr2[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dc2[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int t;
int n, m, p, k, l, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;
	cin >> k;
	DATA st, des;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map1[i][j];
		}
	}
	st.x = 0, st.y = 0, st.k = 0;
	des.x = n - 1, des.y = m - 1;
	queue<DATA> q;
	q.push(st);
	visit[st.x][st.y][0] = true;
	visit[st.x][st.y][1] = true;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int x = q.front().x;
			int y = q.front().y;
			int nk = q.front().k;
			q.pop();
			if (x == des.x && y == des.y) {
				cout << cnt << '\n';
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (visit[nx][ny][nk] == false && map1[nx][ny]==0) {
					visit[nx][ny][nk] = true;
					q.push({ nx,ny, nk });
				}
			}
			if (nk < k) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dr2[i];
					int ny = y + dc2[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visit[nx][ny][nk + 1] == false && map1[nx][ny] == 0) {
						visit[nx][ny][nk + 1] = true;
						q.push({ nx,ny, nk + 1 });
					}
				}
			}
		}
		cnt++;
	}
	cout << -1 << '\n';
	return 0;
}