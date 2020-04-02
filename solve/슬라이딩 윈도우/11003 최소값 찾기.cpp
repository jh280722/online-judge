#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000009
#define MOD2 1000000021
#define INF 1e9
#define N 5000001
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

deque<pii> d;
int ans[N];
int main() {
	SYNC;
	cin >> n >> m;
	fu(i, 0, n) {
		int a;
		cin >> a;
		if (!d.empty() && i - d.front().second >= m) {
			d.pop_front();
		}
		while (!d.empty() && d.back().first > a) {
			d.pop_back();
		}
		d.push_back({ a,i });
		ans[i] = d.front().first;
	}
	fu(i, 0, n)
		cout << ans[i] << ' ';
	return 0;
}