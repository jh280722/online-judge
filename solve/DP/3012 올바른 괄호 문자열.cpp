#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 100000
#define INF 1000000000
#define N 201
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
ll d[N][N];
string s;
string p1 = "({[";
string p2 = ")}]";
ll go(int i, int j) {
	if (i > j) return 1;
	if (d[i][j] != -1) return d[i][j];
	d[i][j] = 0;
	for (int k = i + 1; k <= j; k += 2) {
		for (int l = 0; l < 3; l++) {
			if (s[i] == p1[l] || s[i] == '?') {
				if (s[k] == p2[l] || s[k] == '?') {
					ll temp = go(i + 1, k - 1) * go(k + 1, j);
					d[i][j] += temp;
					if (d[i][j] >= MOD) {
						d[i][j] = MOD + d[i][j] % MOD;
					}
				}
			}
		}
	}
	return d[i][j];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> s;
	memset(d, -1, sizeof d);
	//d[i][j] = ½Ã±×¸¶ d[i+1][k-1]*d[k+1][j]
	ll ans = go(0, n - 1);
	if (ans >= MOD) {
		printf("%05lld\n", ans % MOD);
	}
	else {
		printf("%lld\n", ans);
	}
	return 0;
}