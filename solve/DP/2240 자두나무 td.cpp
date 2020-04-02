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

int d[1001][31];
int a[1001];

int go(int t, int w) {
	if (t == n + 1 && w <= m)return 0;
	if (w > m) return 0;
	if (d[t][w] != -1) return d[t][w];
	int pos = w % 2 + 1;
	d[t][w] = max(go(t + 1, w), go(t + 1, w + 1)) + (pos == a[t]);
	return d[t][w];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	fu(i, 1, n + 1) {
		cin >> a[i];
	}
	memset(d, -1, sizeof d);
	cout << max(go(1, 0), go(1, 1));
	return 0;
}