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
int s[N];
short idx[N][N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		s[0] = 0;
		cin >> n;
		fu(i, 1, n + 1) {
			cin >> s[i];
			s[i] = s[i - 1] + s[i];
			idx[i][i] = i;
		}
		fd(i, n - 1, 1) {
			fu(d, 1, n - i + 1) {
				int j = i + d;
				dp[i][j] = INF;
				fu(k, idx[i][j - 1], idx[i + 1][j] + 1) {
					int tmp = dp[i][k - 1] + dp[k][j] + s[j] - s[i - 1];
					if (tmp < dp[i][j]) {
						dp[i][j] = tmp;
						idx[i][j] = k;
					}
				}
			}
		}
		cout << dp[1][n] << '\n';
	}
	return 0;
}