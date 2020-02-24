#include <iostream>
#include <string.h>
#include <queue>
#define MAX 501
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
char map[5][5];
bool check[1 << 25];
void dfs(int state, int dasom, int cnt) {
	if (dasom + 7 - cnt < 4) return;
	check[state] = true;
	if (cnt == 7) {
		if (dasom < 4)
			return;
		ans++;
		return;
	}

	for (int i = 0; i < 25; i++) {
		int r = i / 5;
		int c = i % 5;
		if (!(state & 1 << i))continue;
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (nr > 4 || nr < 0 || nc>4 || nc < 0) continue;
			int nstate = state | (1 << (nr * 5 + nc));
			if (state & (1 << (nr * 5 + nc)) || check[nstate])continue;
			dfs(nstate, dasom + (map[nr][nc] == 'S'), cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < 25; i++) {
		int r = i / 5;
		int c = i % 5;
		dfs(1<<i, map[r][c] == 'S', 1);
	}
	cout << ans << '\n';
	return 0;
}