#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 51
#define INF 2147000000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, k, t;
int ans = 0;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };

int map[MAX][MAX];
int tmp[MAX][MAX];
int mr, mc;

void spread() {
	memset(tmp, 0, sizeof(tmp));
	f(i, n) {
		f(j, m) {
			if (map[i][j] != 0) {
				int cnt = 0;
				f(k, 4) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
					if ((nr == mr && nc == mc) || (nr == mr - 1 && nc == mc)) continue;
					cnt++;
					tmp[nr][nc] += map[i][j] / 5;
				}
				tmp[i][j] += map[i][j] - map[i][j] / 5 * cnt;
			}
		}
	}
	memcpy(map, tmp, sizeof(map));
}

void wind() {
	for (int i = mr - 2; i > 0; i--) {
		map[i][0] = map[i - 1][0];
	}
	for (int i = mr + 1; i < n - 1; i++) {
		map[i][0] = map[i + 1][0];
	}

	for (int i = 0; i < m - 1; i++) {
		map[0][i] = map[0][i + 1];
	}
	for (int i = 0; i < m - 1; i++) {
		map[n - 1][i] = map[n - 1][i + 1];
	}

	for (int i = 0; i < mr - 1; i++) {
		map[i][m - 1] = map[i + 1][m - 1];
	}
	for (int i = n - 1; i > mr; i--) {
		map[i][m - 1] = map[i - 1][m - 1];
	}

	for (int i = m - 1; i > 1; i--) {
		map[mr - 1][i] = map[mr - 1][i - 1];
	}
	for (int i = m - 1; i > 1; i--) {
		map[mr][i] = map[mr][i - 1];
	}
	map[mr - 1][1] = 0;
	map[mr][1] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	f(i, n) {
		f(j, m) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				mr = i, mc = j;//아래 기준
			}
		}
	}
	while (k--) {
		spread();
		wind();
	}

	f(i, n) {
		f(j, m) {
			if (map[i][j] != -1)
				ans += map[i][j];
		}
	}
	cout << ans << '\n';
	return 0;
}