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

int n, m, k, t;
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int vt[N];
vpii e[N];
int dp[N];
int par[N];
int ans[N];

int maxDiff(int v, int p)
{
	par[v] = p;
	if (vt[v] == 1) dp[v] = 1;
	else dp[v] = -1;

	for (auto& it : e[v])
	{
		if (it.first == p) continue;
		int res = maxDiff(it.first, v);

		if (res >= 0)
		{
			dp[v] += res;
			it.second = 1;
		}
	}

	return dp[v];
}
void solve(int v, bool flag)
{
	int& res = ans[v];
	res = dp[v];
	for (auto& it : e[v])
	{
		if (it.first == par[v])
		{
			if (flag)
			{
				res = max(res, ans[it.first]);
			}
			else
			{
				res = max(res, res + ans[it.first]);
			}
			break;
		}
	}

	for (auto it : e[v])
	{
		if (it.first == par[v]) continue;
		solve(it.first, it.second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fill(dp, dp + N, -INF);
	fu(i, 1, n + 1) {
		cin >> vt[i];//1 white 0 black max(cntw - cntb)
	}
	fu(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v, 0);
		e[v].pb(u, 0);
	}
	maxDiff(1, 0);
	solve(1, 0);
	fu(i, 1, n + 1) {
		cout << ans[i] << ' ';
	}
	return 0;
}