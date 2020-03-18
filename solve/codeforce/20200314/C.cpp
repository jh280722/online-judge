#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define pb(a,b) push_back({a,b})
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define N 200001
#define MOD 1000000
#define INF 1000000000
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

vpii tree[100001];
int ans[100001];
bool chk[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fill(ans, ans + n, -1);
	fu(i, 0, n-1) {
		int u, v;
		cin >> u >> v;
		tree[u].pb(v, i);
		tree[v].pb(u, i);
	}
	bool flg = false;
	int val = 0;

	fu(i, 1, n+1) {
		if (tree[i].size() >= 3) {
			ans[tree[i][0].second] = val++;
			ans[tree[i][1].second] = val++;
			ans[tree[i][2].second] = val++;
			break;
		}
	}
	fu(i, 0, n - 1) {
		if (ans[i] == -1) {
			ans[i] = val++;
		}
		cout << ans[i] << '\n';
	}

	return 0;
}