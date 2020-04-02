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
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) {
			cout << -1 << '\n';
			continue;
		}
		string s;
		s += '3';
		if (2 * (n - 1) % 3 == 0)
			s += '4';
		else
			s += '2';
		fu(i, 0, n - 2)
			s += '2';
		reverse(all(s));
		cout << s << '\n';
	}
	return 0;
}