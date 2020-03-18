#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define pb(a,b) push_back({a,b})
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000
#define INF 1000000000
#define N 501
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
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
int dp[N][N];
int Map[N][N];

int go(int r, int c) {
	if (r == n && c == m) return 1;
	if (dp[r][c] >= 0) return dp[r][c];
	dp[r][c] = 0;
	fu(i, 0, 4) {
		int nr = r + dr[i], nc = c + dc[i];
		if (nr <= 0 || nr > n || nc <= 0 || nc > m) continue;
		if (Map[nr][nc] < Map[r][c])
			dp[r][c] += go(nr, nc);
	}
	return dp[r][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	fu(i, 1, n+1) {
		fu(j, 1, m+1) {
			cin >> Map[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	cout << go(1, 1);
	return 0;
}