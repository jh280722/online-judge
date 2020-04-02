#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 998244353
#define MOD2 1000000021
#define INF 1e9
#define N 200001
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
int dr[] = { 0,0,1,-1, -1,1,1,-1 };
int dc[] = { -1,1,0,0, 1,1,-1,-1 };

ll ans[N];
ll ten_pow[N];

int main() {
	SYNC;
	cin >> n;
	ten_pow[0] = 1;
	fu(i, 1, n + 1)
		ten_pow[i] = ten_pow[i - 1] * 10 % MOD;
	fu(i,1,n) {
		if (i <= n - 2)
			ans[i] = (ll)81 * ten_pow[n - i - 2] % MOD * (n - i - 1) % MOD;
		ans[i] = (ans[i] + 9 * ten_pow[n - i - 1] * 2) % MOD;
	}
	ans[n] = 1;
	fu(i, 1, n+1) {
		ans[i] = (ans[i] * 10) % MOD;
	}
	fu(i, 1, n+1) {
		cout << ans[i] << ' ';
	}
	return 0;
}