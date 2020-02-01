#include <iostream>
#include <queue>
#include <unordered_map>
#define ll long long
using namespace std;

struct DATA {
	int r, c;
	int dir;
};

const int MAX = 21;
const int INF = 2147400000;
char map[MAX][MAX];
unordered_map<int, bool> isUsed[MAX][MAX];

//0 up 1 right 2 down 3 left
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;

queue<DATA> q;

void dfs(int r, int c, int chk, int cnt) {
	if (isUsed[r][c][chk]) {
		return;
	}
	isUsed[r][c][chk] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		if (chk & (1 << map[nr][nc])) continue;
		dfs(nr, nc, chk | (1 << map[nr][nc]), cnt + 1);
	}	
	if (ans < cnt) {
		ans = cnt;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			map[i][j] -= 'A';
		}
	}
	dfs(0, 0, (1<<map[0][0]), 1);
	cout << ans << '\n';
	return 0;
}