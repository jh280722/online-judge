#include <iostream>
#include <queue>
#include <deque>
#define ll long long
using namespace std;

struct DATA {
	int r, c;
	int dir;
};

const int MAX = 101;
const int INF = 2147400000;
int map[MAX][MAX];
int visit[MAX][MAX];

//0 up 1 right 2 down 3 left
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;
char gear[4][8];//[i][0]이 12시 방향

void rotate_gear(int n, int dir) {
	if (dir == 1) {
		char tmp = gear[n][7];
		for (int i = 7; i > 0; i--) {
			gear[n][i] = gear[n][i - 1];
		}
		gear[n][0] = tmp;
	}
	else {
		char tmp = gear[n][0];
		for (int i = 0; i < 7; i++) {
			gear[n][i] = gear[n][i + 1];
		}
		gear[n][7] = tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 4; i++) {
		cin >> gear[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n, dir;
		cin >> n >> dir;
		if (dir == -1)
			dir = 0;
		n--;
		int rn = n, ln = n;
		int rd = !dir, ld = !dir;
		//[i][2] 오른쪽 [i][6] 왼쪽 맞닿은 부분
		while (ln > 0 && gear[ln - 1][2] != gear[ln][6])
			ln--;
		while (rn < 3 && gear[rn + 1][6] != gear[rn][2])
			rn++;
		rotate_gear(n, dir);
		for (int j = n - 1; j >= ln; j--) {
			rotate_gear(j, ld);
			ld = !ld;
		}
		for (int j = n + 1; j <= rn; j++) {
			rotate_gear(j, rd);
			rd = !rd;
		}
	}

	ans = gear[0][0]-'0' + (gear[1][0] - '0') * 2 + (gear[2][0] - '0') * 4 + (gear[3][0] - '0') * 8;
	cout << ans << '\n';
	return 0;
}