#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define pb(a,b) push_back({a,b})
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000007
#define INF 1000000000
#define N 31
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

ll d[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	d[1] = 1, d[2] = 3;
	fu(i, 3, n + 1) {
		d[i] = d[i - 1] + d[i - 2] * 2;
	}
	if (n >= 3) {
		ll b = 0;
		if (n % 2 == 1)
			b = d[(n - 1) / 2];
		else
			b = d[n / 2] + 2 * d[n / 2 - 1];
		d[n] = (d[n] + b) / 2;
	}
	cout << d[n];
	return 0;
}