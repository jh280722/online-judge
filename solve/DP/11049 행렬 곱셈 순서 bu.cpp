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
int a[N][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fu(i, 0, n) {
		cin >> a[i][0] >> a[i][1];
	}
	fd(i, n - 1, 0) {
		fu(j, i + 1, n) {
			dp[i][j] = INF;
			fu(k, i, j + 1) {
				int tmp = dp[i][k] + dp[k + 1][j] + a[i][0] * a[k][1] * a[j][1];
				if (tmp < dp[i][j])
					dp[i][j] = tmp;
			}
		}
	}
	cout << dp[0][n - 1] << '\n';
	return 0;
}