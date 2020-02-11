#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 1000000000
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
	int dir, g;
};
int n, m, t, k;
int ans;
bool map[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };

DATA dg[21];

void rotate(bool map[][MAX], int r,int c) {
	bool tmp[MAX][MAX] = { 0, };
	bool tmp2[MAX][MAX] = { 0, };
	memcpy(tmp, map, sizeof(tmp));
	int nr, nc;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if(j - c + r >= 0&& -i + r + c>=0 && tmp[i][j])
				tmp2[j - c + r][-i + r + c] = tmp[i][j];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if(tmp2[i][j])
				map[i][j] = tmp2[i][j];
		}
	}

}

void curve(DATA d) {
	bool tmp[MAX][MAX] = { 0, };

	memset(visit, 0, sizeof(visit));
	visit[d.r][d.c] = true;
	tmp[d.r][d.c] = true;
	int nr = d.r + dr[d.dir], nc = d.c + dc[d.dir];
	visit[nr][nc] = true;
	tmp[nr][nc] = true;
	for (int i = 1; i <= d.g; i++) {
		rotate(tmp, nr, nc);
		int nnr, nnc;
		nnr = d.c - nc + nr, nnc=  - d.r + nr + nc;
		nr = nnr, nc = nnc;
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (tmp[i][j])
				map[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> dg[i].c >> dg[i].r >> dg[i].dir >> dg[i].g;
		curve(dg[i]);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]) {
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}