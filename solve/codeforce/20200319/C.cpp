#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 998244353
#define INF 1000000000
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
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
pll a[N];
ll idx[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	fu(i, 0, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n, greater<pll>());
	ll sum = 0;
	ll cnt = 1;
	fu(i, 0, k) {
		sum += a[i].first;
		idx[i] = a[i].second;
	}
	if (n == k) cnt = 1;
	else {
		sort(idx, idx + k, greater<ll>());
		fu(i, 0, k - 1) {
			cnt *= (idx[i] - idx[i + 1]);
			cnt %= MOD;
		}
	}
	cout << sum << ' ' << cnt;
	return 0;
}