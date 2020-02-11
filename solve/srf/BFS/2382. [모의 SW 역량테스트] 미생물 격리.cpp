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
	int num;
	int dir;
};
int n, m, t, k;
int ans;
int map[MAX][MAX][4];
bool visit[MAX][MAX][4];
int dr[] = { -1,1,0,0 };
int dc[] = {  0,0,-1,1 };

queue<DATA> q;
int bfs() {
	int lev = 0;
	int cnt = 0;
	while (!q.empty()) {
		bool flag = false;
		int qs = q.size();
		while (qs--) {
			int r = q.front().r;
			int c = q.front().c;
			int num = q.front().num;
			int dir = q.front().dir;
			q.pop();

			int nr = r + dr[dir];
			int nc = c + dc[dir];
			if (nr == 0 || nc == n - 1 || nr == n - 1 || nc == 0) {
				num /= 2;
				if (dir == 0 || dir == 2)
					dir++;
				else if (dir == 1 || dir == 3)
					dir--;
			}
			map[nr][nc][dir] = num;
			visit[nr][nc][dir] = true;
			
		}

		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int dir = 0, max = 0,sum=0;
				for (int k = 0; k < 4; k++) {
					if (!visit[i][j][k]) {
						map[i][j][k] = 0;
						continue;
					}
					sum += map[i][j][k];
					if (max < map[i][j][k]) {
						max = map[i][j][k];
						dir = k;
					}
					map[i][j][k] = 0;
					visit[i][j][k] = false;
				}
				cnt += sum;
				if(sum!=0)
					q.push({ i,j,sum,dir }); 
			}
		}
		lev++;
		if (lev == m)
			break;
	}
	while (!q.empty())
		q.pop();
	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(map, 0, sizeof(map));
		ans = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int r, c, num, dir;
			cin >> r >> c >> num >> dir;
			dir--;
			map[r][c][0] = num;
			map[r][c][dir] = num;
			q.push({ r,c,num, dir });
		}
		ans=bfs();
		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}