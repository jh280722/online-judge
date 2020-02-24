#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
char map[MAX][MAX];
bool vis[MAX][MAX];
struct DATA {
	int w;
	int r, c;
	int dir;
	bool operator()(DATA a, DATA b) {
		return a.w > b.w;
	}
};
priority_queue<DATA,vector<DATA>,DATA> pq;
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
		vis[r][c] = true;
		for (int k = 0; k < 4; k++) {
			if (dir!=-1 && k == (dir + 2) % 4) continue;
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == '*') continue;
			if (vis[nr][nc]) continue;
			if(dir==k)
				pq.push({ w,nr,nc,k });
			else
				pq.push({ w+1,nr,nc,k });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	bool la = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (!la && map[i][j] == 'C') {
				la = true; 
				pq.push({ -1,i,j,-1 });
				vis[i][j] = true;
			}
			if (la && map[i][j] == 'C') {
				dst[0] = i, dst[1] = j;
			}
		}
	}
	bfs();
	cout << ans << '\n';
	return 0;
}