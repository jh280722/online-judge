#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000009
#define MOD2 1000000021
#define INF 1000000000
#define N 21
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); };
int n, m, k, t;
int dr[] = { 1,0,-1,0, -1,1,1,-1 };
int dc[] = { 0,1,0,-1, 1,1,-1,-1 };

char Map[N][N];
int vis[N][N];
int ans;
pii dirty[11];
int p;
int dis[11][11];

void bfs(int src) {
	memset(vis, 0, sizeof vis);
	int ans = 0;
	queue<pii> q;
	q.push(dirty[src]);
	int r = dirty[src].first, c = dirty[src].second;
	vis[r][c] = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		fu(k, 0, 4) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (Map[nr][nc] == 'x' || vis[nr][nc]) continue;
			vis[nr][nc] = vis[r][c] + 1;
			q.push({ nr,nc });
		}
	}
	fu(i, 0, p + 1) {
		dis[src][i] = vis[dirty[i].first][dirty[i].second] - 1;
		if (dis[src][i] < 0)
			dis[src][i] = INF;
	}
}
int dp[11][1 << 11];
int dfs(int n, int msk) {
	if (msk + 1 == 1 << (p + 1)) return 0;

	int& ref = dp[n][msk];
	if (ref != -1) return ref;
	ref = INF;
	fu(i, 1, p + 1) {
		if (msk & (1 << i)) continue;
		ref = min(ref, dfs(i, msk | (1 << i)) + dis[n][i]);
	}
	return ref;
}
int main() {
	SYNC;
	while (true) {
		ans = INF;
		p = 0;
		memset(dis, -1, sizeof dis);
		cin >> m >> n;
		if (!n && !m) break;
		fu(i, 0, n) {
			fu(j, 0, m) {
				cin >> Map[i][j];
				if (Map[i][j] == 'o')
					dirty[0] = { i,j };
				else if (Map[i][j] == '*') {
					dirty[++p] = { i,j };
				}
			}
		}
		fu(i, 0, p + 1)
			bfs(i);
		memset(dp, -1, sizeof dp);
		int ans = dfs(0, 1);
		if (ans == INF)
			ans = -1;
		cout << ans << '\n';
	}
	return 0;
}