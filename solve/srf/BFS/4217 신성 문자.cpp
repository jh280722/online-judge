#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 204
#define INF 2147000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

int map[MAX][MAX];
int vis[MAX][MAX];
int key = 0;
int bfs(int r, int c, int type) {
	int cnt = 0;
	queue<pii> q;
	q.push({ r,c });
	vis[r][c] = key;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		f(k, 4) {
			int nr = r + dr[k], nc = c + dc[k];
			if (nr < 0 || nr >= n + 2 || nc < 0 || nc >= m + 2) continue;
			if (vis[nr][nc]) continue;
			if (map[nr][nc] == type) {
				vis[nr][nc] = key;
				q.push({ nr,nc });
			}
			if (type == 1 && map[nr][nc] == 0) {
				bfs(nr, nc, 0);
				cnt++;
			}
		}
	}
	return cnt;
}
vector<char> ans;
char word[7] = "WAKJSD";
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc = 1;
	while (true) {
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		ans.clear();
		key = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		m = 4 * m;
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j += 4) {
				char a;
				cin >> a;
				int tmp = isdigit(a) ? a - '0' : a - 'a' + 10;
				f(k, 4) {
					map[i][j + k] = (tmp >> 3 - k) & 1;
				}
			}
		}
		//안에 공간이 고유하다.
		key++;
		bfs(0, 0, 0);
		f(i, n + 1) {
			f(j, m + 1) {
				if (vis[i][j]) continue;
				if (map[i][j] == 0) continue;
				key++;
				int tmp = bfs(i, j, 1);
				ans.push_back({ word[tmp] });
			}
		}

		sort(all(ans));
		cout << "Case " << tc++ << ": ";
		f(i, ans.size()) {
			cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}