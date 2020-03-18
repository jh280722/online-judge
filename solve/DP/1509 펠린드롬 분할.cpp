#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define pb(a,b) push_back({a,b})
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000
#define INF 1000000000
#define N 2501
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
int d[N];
bool c[N][N];
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	n = s.size();
	fu(i, 0, n) {
		c[i][i] = 1;
	}
	fu(i, 0, n - 1) {
		if (s[i] == s[i + 1])
			c[i][i + 1] = 1;
	}
	fu(k, 2, n) {
		fu(i, 0, n - k) {
			int j = i + k;
			if (s[i] == s[j] && c[i + 1][j - 1]) {
				//dp[i][j]= dp[i+1][j-1] && s[i]==s[j]
				c[i][j] = 1;
			}
		}
	}
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = -1;
		for (int j = 1; j <= i; j++)
		{
			if (c[j - 1][i - 1]) {
				if (d[i] == -1 || d[i] > d[j - 1] + 1) {
					d[i] = d[j - 1] + 1;
				}
			}
		}
	}
	cout << d[n];
	return 0;
}