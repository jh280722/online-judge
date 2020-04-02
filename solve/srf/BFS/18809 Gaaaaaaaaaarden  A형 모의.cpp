#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1e9+9
#define MOD2 1000000021
#define INF 1e9
#define N 51
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

struct liq {
	bool type;
	pii loc;
};
int ans;
int Map[N][N];
int vis[N][N][2];
int R, G;
vpii land;
queue<liq> q;
int bfs() {
	int f = 0;
	int lev = 0;
	while (!q.empty()) {
		lev++;
		int qs = q.size();
		while (qs--) {
			int r = q.front().loc.first;
			int c = q.front().loc.second;
			bool type = q.front().type;
			q.pop();
			if (vis[r][c][type] == INF)
				continue;
			fu(k, 0, 4) {
				int nr = r + dr[k], nc = c + dc[k];
				if (nr < 0 || nr >= n || nc < 0 || nc >= m || !Map[nr][nc]) continue;
				if (vis[nr][nc][type] != 0) continue;
				vis[nr][nc][type] = vis[r][c][type] + 1;
				if (vis[nr][nc][!type]==vis[nr][nc][type]) {
					vis[nr][nc][!type] = INF;
					vis[nr][nc][type] = INF;
					f++;
				}
				else
					q.push({ type,{nr,nc} });
			}
		}
	}
	return f;
}
int selr[6];
bool ch[11];
int selg[6];

void go(int idx, int r, int g) {
	if (r + g == R + G) {
		fu(i, 0, r) {
			int x = land[selr[i]].first;
			int y = land[selr[i]].second;
			q.push({ 0,land[selr[i]] });
			vis[x][y][0] = 1;
		}
		fu(i, 0, g) {
			int x = land[selg[i]].first;
			int y = land[selg[i]].second;
			q.push({ 1,land[selg[i]] });
			vis[x][y][1] = 1;
		}
		ans = max(ans, bfs());
		memset(vis, 0, sizeof vis);
		return;
	}
	fu(i, idx, land.size()) {
		if (r < R && !ch[i]) {
			selr[r] = i;
			ch[i] = 1;
			go(i + 1, r + 1, g);
			ch[i] = 0;
		}
		if (g < G && !ch[i]) {
			selg[g] = i;
			ch[i] = 1;
			go(i + 1, r, g + 1);
			ch[i] = 0;
		}
	}
}

int main() {
	SYNC;
	cin >> n >> m >> R >> G;
	fu(i, 0, n) {
		fu(j, 0, m) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				land.push_back({ i,j });
			}
		}
	}
	go(0, 0, 0);
	cout << ans << '\n';
	return 0;
}