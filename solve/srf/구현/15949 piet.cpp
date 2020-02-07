#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 1000000000
typedef long long ll;
using namespace std;

struct POINT {
	int r, c;
};
int n, m, t, k;
string ans = "";
char map[MAX][MAX];
bool visit[MAX][MAX];
int dr[] = { 0,1,0,-1 };//우하좌상
int dc[] = { 1,0,-1,0 };//우하좌상
POINT dir[4][2];//우하좌상 dp랑 같이 [4]각 방향 최대 좌표 [2]왼쪽 오른쪽
//처음 dp 오른쪽 cc 왼쪽
//bfs를 dp방향과 cc방향으로 돌아서 가장 멀리 있는 블록을 확인
//cc는 dp의 상대 방향 cc오른쪽은 +1 왼쪽은 -1
//그 다음 map[nr][nc]에서 dp방향으로 가고 해당 블록이 다음 블록
//1. 만약 그 블록이 경계밖이거나 검은색이면('X') cc값을 역(좌우)으로 바꾸고 탐색
//2. 그래도 안되면 cc는 유지하고 dp를 시계방향으로 돌려서 탐색
//1 2번 반복하다가 8가지 다 하면 프로그램 종료.

int dp = 0;
int cc = -1;

void cal(int r, int c) {
	if (dir[0][0].c < c) {	//right
		dir[0][0].c = c;
		dir[0][0].r = r;
		dir[0][1].c = c;
		dir[0][1].r = r;
	}
	else if (dir[0][0].c == c) {
		if (dir[0][0].r > r)//right left
			dir[0][0].r = r;
		if (dir[0][1].r < r)//right right
			dir[0][1].r = r;
	}

	if (dir[1][0].r < r) {	//down
		dir[1][0].r = r;
		dir[1][0].c = c;
		dir[1][1].r = r;
		dir[1][1].c = c;
	}
	else if (dir[1][0].r == r) {
		if (dir[1][0].c < c)//down left
			dir[1][0].c = c;
		if (dir[1][1].c > c)//down right
			dir[1][1].c = c;
	}

	if (dir[2][0].c > c) {	//left left
		dir[2][0].c = c;
		dir[2][0].r = r;
		dir[2][1].c = c;
		dir[2][1].r = r;
	}
	else if (dir[2][0].c == c) {
		if (dir[2][0].r < r)//left left
			dir[2][0].r = r;
		if (dir[2][1].r > r)//left right
			dir[2][1].r = r;
	}

	if (dir[3][0].r > r) {	//up
		dir[3][0].r = r;
		dir[3][0].c = c;
		dir[3][1].c = c;
		dir[3][1].r = r;
	}
	else if (dir[3][0].r == r) {
		if (dir[3][0].c > c)//up left
			dir[3][0].c = c;
		if (dir[3][1].c < c)//up right
			dir[3][1].c = c;
	}
}

void bfs(int r, int c, char color) {
	memset(visit, 0, sizeof(visit));
	queue<POINT> q;
	q.push({ r,c });
	visit[r][c] = true;
	for (register int i = 0; i < 4; i++) {
		for (register int j = 0; j < 2; j++) {
			dir[i][j] = { r,c };
		}
	}
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		cal(r, c);
		q.pop();
		for (register int i = 0; i < 4; i++) {
			register int nr = r + dr[i];
			register int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m || visit[nr][nc]) continue;

			if (map[nr][nc] == color) {
				q.push({ nr,nc });
				visit[nr][nc] = true;
			}
		}
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
		}
	}
	register int r = 0, c = 0;
	register int nr, nc;
	register bool flag = true;
	while (flag) {
		flag = false;
		ans += map[r][c];
		bfs(r, c, map[r][c]);
		for (register int i = 0; i < 4; i++) {
			for (register int j = 0; j < 2; j++) {
				if (cc == -1)
					nr = dir[dp][0].r + dr[dp], nc = dir[dp][0].c + dc[dp];
				else
					nr = dir[dp][1].r + dr[dp], nc = dir[dp][1].c + dc[dp];
				if (nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 'X') {
					if(!j)
						cc *= -1;
				}
				else {
					flag = true;
					break;
				}
			}
			if (flag) {
				r = nr, c = nc;
				break;
			}
			dp += 1;
			dp %= 4;
		}
	}
	cout << ans << '\n';
	return 0;
}