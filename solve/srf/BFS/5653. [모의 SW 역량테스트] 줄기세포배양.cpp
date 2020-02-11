#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 351
#define INF 1000000000
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
	int life;
	int time;
};
int n, m, t, k;
int ans;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
queue<DATA> q;
int bfs() {
	int lev = 0;
	while (!q.empty()) {
		bool flag = false;
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			int life = q.front().life;
			int time = q.front().time;
			q.pop();

			if (time < life) {
				q.push({ r,c,life,time + 1 });
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (visit[nr][nc]) continue;
				if (map[nr][nc] == 0) {
					map[nr][nc] = life;
					visit[nr][nc] = true;
					q.push({ nr,nc,life,0 });
				}
			}			
			if (time + 1 < 2 * life) {
				q.push({ r,c,life,time + 1 });
			}
		}
		lev++;
		if (lev == k)
			break;
	}
	int cnt = 0;
	while (!q.empty()) {
		q.pop();
		cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
		ans = INF;
		cin >> n >> m >> k;
		vector<DATA> v;
		for (int i = 150; i < 150+n; i++) {
			for (int j = 150; j < 150+m; j++) {
				cin >> map[i][j];
				if (map[i][j] != 0) {
					visit[i][j] = true;
					v.push_back({ i,j,map[i][j],0 });
				}
			}
		}
		sort(all(v), [](DATA a, DATA b) {return a.life > b.life; });
		for (int i = 0; i < v.size(); i++)
			q.push({ v[i].r,v[i].c,v[i].life,0 });
		ans=bfs();

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}