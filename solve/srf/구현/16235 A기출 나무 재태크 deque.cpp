#include <iostream>
#include <algorithm>
#include <queue>
#define all(v) v.begin(), v.end()
#define MAX 11
#define INF 1000000000
typedef long long ll;
using namespace std;

int n, m, t, k;
int tree[MAX][MAX];//나이별 나무 갯수
int food[MAX][MAX];//전체 양분(나무가 죽은)
int add[MAX][MAX];//추가되는 양분
int ans;

struct TREE {
	int age;
	int r,c;
	bool operator()(TREE &a, TREE &b) {
		return a.age > b.age;
	}
};
int dr[] = { 1,0,-1,0, 1,-1,1,-1 };
int dc[] = { 0,1,0,-1,1,-1,-1,1 };

deque <int> q[MAX][MAX];

void spring() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int qs = q[i][j].size();
			if (qs == 0) continue;
			int sum = 0;
			while (qs--) {
				int age = q[i][j].front();
				q[i][j].pop_front();
				if (age <= food[i][j]) {
					food[i][j] -= age;
					q[i][j].push_back(age + 1);
				}
				else
					 sum+= age / 2;
			}
			food[i][j] += sum;
		}
	}
}

void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int qs = q[i][j].size();
			for(int k=0;k<qs;k++){
				if (q[i][j][k] % 5 != 0) continue;
				for (int d = 0; d < 8; d++) {
					int nr = i + dr[d];
					int nc = j + dc[d];
					if (nr <= 0 || nr > n || nc <= 0 || nc > n) continue;
					q[nr][nc].push_front(1);
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			food[i][j] += add[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;//k년후 살아있는 나무 수
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> add[i][j];//로봇이 추가하는 양분
			food[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		q[r][c].push_back(age);
	}
	while (k--) {
		spring();
		fall();
		winter();
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += q[i][j].size();
		}
	}
	cout << ans << '\n';
	return 0;
}