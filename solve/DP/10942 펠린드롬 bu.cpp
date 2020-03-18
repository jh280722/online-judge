#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define pb(a,b) push_back({a,b})
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000
#define INF 1000000000
#define N 2001
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
int d[N][N];
int a[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fu(i, 0, n) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) d[i][i] = true;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) d[i][i + 1] = true;
	}
	for (int k = 3; k <= n; k++) {
		for (int i = 0; i < n - k + 1; i++) {
			int j = i + k - 1;
			if (a[i] == a[j] && d[i + 1][j - 1]) {
				d[i][j] = true;
			}
		}
	}
	cin >> m;
	fu(i, 0, m) {
		int s, e;
		cin >> s >> e;
		cout << d[s - 1][e - 1] << '\n';
	}
	return 0;
}