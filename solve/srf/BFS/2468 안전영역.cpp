#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 214700000
typedef long long ll;
using namespace std;

int n, t, ans;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dis[MAX][MAX];

struct DATA {
	int r, c;
};

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };

void bfs(int r, int c, int d) {
	queue<DATA> q;
	q.push({ r,c });
	visit[r][c] = true;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n || visit[nr][nc]) continue;

			if (map[nr][nc] > d) {
				q.push({ nr,nc });
				visit[nr][nc] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int max = 1;
	for (int d = 1; d < 100; d++) {
		int cnt = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && map[i][j] > d) {
					bfs(i, j, d);
					cnt++;
				}
			}
		}
		if (cnt == 0)
			break;
		max = max > cnt ? max : cnt;
	}
	cout << max;
	return 0;
}