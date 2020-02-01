#include <iostream>
#include <queue>
#include <string.h>
#define ll long long
using namespace std;

struct DATA {
	int r, c;
};

const int MAX = 21;
const int INF = 2147400000;
char map[MAX][MAX];
bool visit[MAX][MAX];

//0 up 1 right 2 down 3 left
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;

queue<DATA> q;

bool bfs(int x, int y, char c1) {
	memset(visit, false, sizeof(visit));
	int cnt = 1;
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int x = q.front().r;
			int y = q.front().c;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dr[i];
				int ny = y + dc[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

				if (visit[nx][ny] == false && (map[nx][ny] == c1)) {
					cnt++;
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (cnt >= 4) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j])
					map[i][j] = '.';
			}
		}
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	n = 12; m = 6;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	while (true) {
		bool chain = false;
		bool ch = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != '.') {
					ch = bfs(i, j, map[i][j]);
					if (ch)
						chain = true;
				}
			}
		}
		if (chain)
			ans++;
		else
			break;

		for (int j = 0; j < m; j++)
		{
			int idx = n-1;
			for (int i = n-1; i >= 0; i--)
			{
				if (map[idx][j] != '.') idx--;
				else if (map[i][j] != '.')
				{
					map[idx][j] = map[i][j];
					map[i][j] = '.';
					idx--;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}