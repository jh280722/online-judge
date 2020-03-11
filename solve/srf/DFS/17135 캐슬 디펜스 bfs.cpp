#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#define MAX 16
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int ans;
int d;
int Map[MAX][MAX];
int tmp[MAX][MAX];
bool vis[MAX][MAX];
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
int archer[3];
//d만큼 거리 찾아서 왼쪽 우선


bool move() {
	f(i, 0, m) {
		for(int j=n-1;j>0;j--) {
			Map[j][i] = Map[j - 1][i];
		}
		Map[0][i] = 0;
	}
	f(i, 0, n)
		f(j, 0, m)
		if (Map[i][j] != 0)
			return false;
	return true;
}

void bfs() {
	int score = 0;
	while (true) {
		pii LH[3];
		f(i, 0, 3) {
			bool flag = false;
			LH[i].first = n, LH[i].second = archer[i];
			memset(vis, 0, sizeof vis);
			vis[n][archer[i]] = true;
			queue<pii> q;
			q.push({ n,archer[i] });
			int lev = 0;
			while (!q.empty()) {
				int qs = q.size();
				while (qs--) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
					if (Map[r][c] == 1) {
						if (!flag)
							LH[i].first = r, LH[i].second = c, flag = true;
						else {
							if (LH[i].second  > c) {
								LH[i].first = r, LH[i].second = c;
							}
						}
					}
					if (flag)
						continue;
					f(k, 0, 3) {
						int nr = r + dr[k];
						int nc = c + dc[k];
						if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
						if(vis[nr][nc]) continue;
						q.push({ nr,nc });
						vis[nr][nc] = true;
					}
				}
				lev++;
				if (lev > d || flag)
					break;
			}
		}
		f(i, 0, 3) {
			if (Map[LH[i].first][LH[i].second]) {
				score++;
				Map[LH[i].first][LH[i].second] = 0;
			}
		}
		if (move())
			break;
	}
	ans = max(ans, score);
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		memcpy(Map, tmp, sizeof Map);
		bfs();
		return;
	}

	f(i, idx, m) {
		archer[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> d;
	f(i, 0, n)
		f(j, 0, m)
		cin >> tmp[i][j];//1 적
	dfs(0, 0);

	cout << ans;
	return 0;
}