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
int a[N];
int s[N];

int go(int i, int j) {
	if (dp[i][j] != -1)
		return dp[i][j];
	if (i == j) return 0;

	fu(k, i, j) {
		int tmp = go(i, k) + go(k + 1, j) + s[j] - s[i - 1];
		if (dp[i][j] == -1 || dp[i][j]>tmp)
			dp[i][j] = tmp;
	}

	return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof dp);
		memset(s, 0, sizeof s);
		cin >> n;
		fu(i, 1, n + 1) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}

		cout << go(1, n) << '\n';
	}
	return 0;
}