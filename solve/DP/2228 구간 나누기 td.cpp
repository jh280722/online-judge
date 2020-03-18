#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define pb(a,b) push_back({a,b})
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000
#define INF 1000000000
#define N 101
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
int dp[N][N / 2 + 1];
bool c[N][N / 2 + 1];
int s[N];

int Min = -INF;
int go(int n, int m) {
	if (m == 0) return 0;
	if (n <= 0) return Min;
	if (c[n][m]) return dp[n][m];
	c[n][m] = true;
	dp[n][m] = go(n - 1, m);
	fu(i, 1, n + 1) {
		dp[n][m] = max(dp[n][m], go(i - 2, m - 1) + s[n] - s[i - 1]);
	}
	return dp[n][m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	fu(i, 1, n + 1) {
		int a;
		cin >> a;
		s[i] = s[i - 1] + a;
	}
	cout << go(n, m) << '\n';
	return 0;
}