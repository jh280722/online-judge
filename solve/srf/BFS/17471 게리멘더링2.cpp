#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 21
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int ans = INF;
int total;
int map[MAX][MAX];
int vis[MAX][MAX];

bool bfs(int r, int c, int d1, int d2) {
	memset(vis, 0, sizeof vis);
	queue<pii> q;
	int result[5] = { 0 };
	vis[r][c] = 5;
	f(i, 1, d1 + 1) {
		vis[r + i][c - i] = 5;
	}
	f(i, 1, d2 + 1) {
		vis[r + i][c + i] = 5;
	}
	f(i, 0, d2 + 1) {
		vis[r + d1 + i][c - d1 + i] = 5;
	}
	f(i, 0, d1 + 1) {
		vis[r + d2 + i][c + d2 - i] = 5;
	}

	q.push({ 1,1 });
	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		f(k, 0, 4) {
			int nr = rr + dr[k];
			int nc = cc + dc[k];
			if (nr <= 0 || nr >= n || nc <= 0 || nc >= n) continue;
			if (vis[nr][nc] != 0) continue;

			if (1 <= nr && nr < r + d1 && 1 <= nc && nc <= c) {
				vis[nr][nc] = 1;
			}
			else if (1 <= nr && nr <= r + d2 && c < nc && nc < n) {
				vis[nr][nc] = 2;
			}
			else if (r + d1 <= nr && nr < n && 1 <= nc && nc < c - d1 + d2) {
				vis[nr][nc] = 3;
			}
			else if (r + d2 < nr && nr < n && c - d1 + d2 <= nc && nc < n) {
				vis[nr][nc] = 4;
			}
			q.push({ nr,nc });
		}
	}
	f(i, 1, n) {
		f(j, 1, n) {
			if (vis[i][j] == 0) continue;
			result[vis[i][j] - 1] += map[i][j];
		}
	}
	result[4] = total;
	f(i, 0, 4) {
		result[4] -= result[i];
	}
	int Min = *min_element(result, result + 5);
	int Max = *max_element(result, result + 5);
	ans = min(ans, Max - Min);
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	n++;

	f(i, 1, n) {
		f(j, 1, n) {
			cin >> map[i][j];
			total += map[i][j];
		}
	}
	// (d1, d2 ¡Ã 1, 1 ¡Â x < x+d1+d2 ¡Â N, 1 ¡Â y-d1 < y < y+d2 ¡Â N)
	f(r, 1, n) {
		f(c, 1, n) {
			f(d2, 1, n - c) {
				f(d1, 1, n - d2 - r) {
					if (1 <= r && r < r + d1 + d2 && r < n - d1 - d2 && 1 <= c - d1 && c < c + d2 && c < n - d2)
						bfs(r, c, d1, d2);
				}
			}
		}
	}
	cout << ans;

	return 0;
}