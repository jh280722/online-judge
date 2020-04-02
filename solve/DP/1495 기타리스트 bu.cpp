#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define pb(a,b) push_back({a,b})
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000007
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

bool d[N][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s;
	cin >> n >> s >> m;
	d[0][s] = 1;
	fu(i, 1, n + 1) {
		int a;
		cin >> a;
		fu(j, 0, m + 1) {
			if (!d[i - 1][j]) continue;
			if (j + a <= m)
				d[i][j + a] = 1;
			if (j - a >= 0)
				d[i][j - a] = 1;
		}
	}
	fd(i, m, 0)
		if (d[n][i]) {
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}