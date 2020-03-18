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
int Map[N][N];
ll dp[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fu(i, 0, n)
		fu(j, 0, n)
		cin >> Map[i][j];
	dp[0][0] = 1;
	fu(i, 0, n) {
		fu(j, 0, n) {
			if (Map[i][j] == 0) continue;
			if (j + Map[i][j] < n)
				dp[i][j + Map[i][j]] += dp[i][j];
			if (i + Map[i][j] < n)
				dp[i + Map[i][j]][j] += dp[i][j];
		}
	}
	cout << dp[n - 1][n - 1];
	return 0;
}