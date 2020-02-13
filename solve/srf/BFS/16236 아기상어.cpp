#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 21
#define INF 2147483647
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
};
int n, m, t, k;
int ans;

int map[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = { -1,0,0,1 };
int dc[] = { 0,-1,1,0 };

queue<DATA> q;
int s = 2, f;
DATA LH;
bool bfs() {
	bool flag = false;
	int lev = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			q.pop();
			if (map[r][c] > 0 && map[r][c] < s) {
				if (!flag)
					LH.r = r, LH.c = c,flag = true;
				else {
					if (LH.r > r || (LH.r == r && LH.c > c)) {
						LH.r = r, LH.c = c;
					}
				}
			}
			if (flag)
				continue;
			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k], nc = c + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n || visit[nr][nc]) continue;
				if (map[nr][nc] > s) continue;
				q.push({ nr,nc });
				visit[nr][nc] = true;
			}
		}
		if (flag) {
			map[LH.r][LH.c] = 0;
			f += 1;
			if (f == s)
				s++, f = 0;
			ans += lev;
			return true;
		}
		lev++;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9)
				map[i][j] = 0, LH.r = i, LH.c = j;
		}
	}

	while (true) {
		bool flag = false;
		memset(visit, 0, sizeof(visit));
		q.push({ LH.r,LH.c });
		visit[LH.r][LH.c] = true;
		flag=bfs();
		if (!flag)
			break;
		while (!q.empty())
			q.pop();
	}
	cout << ans << '\n';
	return 0;
}