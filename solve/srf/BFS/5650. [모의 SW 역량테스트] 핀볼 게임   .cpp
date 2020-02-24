#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 214700000
typedef long long ll;
using namespace std;

int n, m, t, a, ans;

struct hole {
	int num;
	int r, c;
};

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int map[MAX][MAX];
hole wormhole[5][2];
void move(int r, int c, int dir) {
	int score = 0;
	int nr = r, nc = c;
	while (true) {
		nr = nr + dr[dir];
		nc = nc + dc[dir];
		if (nr == r && nc == c)
			break;
		if (map[nr][nc] == -1)
			break;
		if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
			dir = (dir + 2) % 4;
			score++;
			continue;
		}
		if (map[nr][nc] == 0) continue;
		if (map[nr][nc] > 0 && map[nr][nc] < 6) {
			switch (map[nr][nc]) {
			case 1:
				if (dir == 0 || dir == 1)
					dir = (dir + 2) % 4;
				else if (dir == 2)
					dir = 1;
				else
					dir = 0;
				break;
			case 2:
				if (dir == 1 || dir == 2)
					dir = (dir + 2) % 4;
				else if (dir == 0)
					dir = 1;
				else
					dir = 2;
				break;
			case 3:
				/*int dr[] = { -1,0,1,0 };
				  int dc[] = { 0,1,0,-1 };*/
				if (dir == 2 || dir == 3)
					dir = (dir + 2) % 4;
				else if (dir == 0)
					dir = 3;
				else
					dir = 2;
				break;
			case 4:
				if (dir == 3 || dir == 0)
					dir = (dir + 2) % 4;
				else if (dir == 1)
					dir = 0;
				else
					dir = 3;
				break;
			case 5:
				dir = (dir + 2) % 4;
				break;
			}
			score++;
		}
		else {
			int whr = wormhole[map[nr][nc] - 6][0].r;
			int whc = wormhole[map[nr][nc] - 6][0].c;
			int whr2 = wormhole[map[nr][nc] - 6][1].r;
			int whc2= wormhole[map[nr][nc] - 6][1].c;
			if (whr == nr && whc == nc) {
				nr = whr2, nc = whc2;
			}
			else
				nr = whr, nc = whc;
		}
	}
	ans = max(ans, score);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(wormhole, 0, sizeof(wormhole));
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] > 5) {
					if(wormhole[map[i][j] - 6][0].num==1)
						wormhole[map[i][j] - 6][1] = {2, i,j };
					else
						wormhole[map[i][j] - 6][0] = {1, i,j };
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0) continue;
				for(int k=0;k<4;k++)
					move(i, j, k);
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}