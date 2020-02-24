#include <iostream>
#include <string.h>
#include <queue>
#define MAX 51
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
char map[MAX][MAX];
bool vis[MAX][MAX][4];
struct DATA {
	int w;
	int r, c;
	int dir;
	bool operator()(DATA a, DATA b) {
		return a.w > b.w;
	}
};
priority_queue<DATA, vector<DATA>, DATA> pq;
int dst[2];
void bfs() {
	while (!pq.empty()) {
		int r = pq.top().r;
		int c = pq.top().c;
		int w = pq.top().w;
		int dir = pq.top().dir;
		pq.pop();
		if (r == dst[0] && c == dst[1]) {
			ans = w;
			return;
		}
		vis[r][c][dir] = true;
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] == '*') continue;
		if (vis[nr][nc][dir]) continue;
		if (map[nr][nc] == '!') {
			pq.push({ w,nr,nc,dir });
			if(dir+1>3)
				pq.push({ w + 1,nr,nc,0 });
			else
				pq.push({ w + 1,nr,nc,dir+1 });
			if (dir - 1 < 0)
				pq.push({ w + 1,nr,nc,3 });
			else
				pq.push({ w + 1,nr,nc,dir - 1 });
		}
		else {
			pq.push({ w,nr,nc,dir });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	bool la = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (!la && map[i][j] == '#') {
				la = true;
				for (int k = 0; k < 4; k++)
					pq.push({ 0,i,j,k });
			}
			if (la && map[i][j] == '#') {
				dst[0] = i, dst[1] = j;
			}
		}
	}
	bfs();
	cout << ans << '\n';
	return 0;
}