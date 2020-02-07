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
int dr[] = { 0,1,0,-1 };//�����»�
int dc[] = { 1,0,-1,0 };//�����»�
POINT dir[4][2];//�����»� dp�� ���� [4]�� ���� �ִ� ��ǥ [2]���� ������
//ó�� dp ������ cc ����
//bfs�� dp����� cc�������� ���Ƽ� ���� �ָ� �ִ� ����� Ȯ��
//cc�� dp�� ��� ���� cc�������� +1 ������ -1
//�� ���� map[nr][nc]���� dp�������� ���� �ش� ����� ���� ���
//1. ���� �� ����� �����̰ų� �������̸�('X') cc���� ��(�¿�)���� �ٲٰ� Ž��
//2. �׷��� �ȵǸ� cc�� �����ϰ� dp�� �ð�������� ������ Ž��
//1 2�� �ݺ��ϴٰ� 8���� �� �ϸ� ���α׷� ����.

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