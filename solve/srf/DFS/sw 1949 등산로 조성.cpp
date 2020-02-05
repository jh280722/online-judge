#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 9
#define INF 1000000000
typedef long long ll;
using namespace std;

int n, m, t, k;
int map[MAX][MAX];
int visit[MAX][MAX];
int ans;

struct DATA {
	int r, c;
	int h;
	bool k;
};
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };


vector<DATA> mt;
int mh;
void dfs(int idx, int r, int c, int h, bool kch, int cnt) {
	if(map[r][c] + cnt < ans)
		return;
	ans = max(ans, cnt);

	visit[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n)continue;
		if (visit[nr][nc])continue;
		if (map[nr][nc] < h) {
			visit[nr][nc] = true;
			dfs(idx, nr, nc, map[nr][nc], kch, cnt + 1);
			visit[nr][nc] = false;
		}
		else if (!kch && map[nr][nc] - h < k) {
			kch = true;
			visit[nr][nc] = true;
			dfs(idx, nr, nc, h - 1, kch, cnt + 1);
			visit[nr][nc] = false;
			kch = false;
		}
	}
	visit[r][c] = false;
	if (idx + 1 < mt.size() && mh == h)
		dfs(idx + 1, mt[idx + 1].r, mt[idx + 1].c, mh, false, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		mt.clear();
		mh = 0;
		ans = 0;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				cin >> map[j][l];
				if (mh < map[j][l])
					mh = map[j][l];
			}
		}

		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				if (mh == map[j][l])
					mt.push_back({ j,l });
			}
		}
		dfs(0, mt[0].r, mt[0].c, mh, false, 1);
		cout << "#" << i << ' ' << ans << '\n';
	}
	return 0;
}