#include <iostream>
#include <string.h>
#include <queue>
#include <unordered_map>
#define MAX 21
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans;
int dr[] = { 0, 0,0,-1,1 };
int dc[] = { 0, 1,-1,0,0 };
int map[MAX][MAX];


int dice[7];
void roll(int dir) {
	if (dir == 1) {
		int tmp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = tmp;
	}
	else if (dir == 2) {
		int tmp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = tmp;
	}
	else if (dir == 3) {
		int tmp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = tmp;

	}
	else {
		int tmp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = tmp;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n>>m;
	int r, c;
	cin >> r >> c;
	cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int command;
		cin >> command;
		int nr = r + dr[command];
		int nc = c + dc[command];
		if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
		r = nr, c = nc;
		roll(command);
		if (map[r][c] == 0) {
			map[r][c] = dice[6];
		}
		else {
			dice[6] = map[r][c];
			map[r][c] = 0;
		}
		cout << dice[1] << '\n';
	}

	return 0;
}