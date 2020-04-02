#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 998244353
#define INF 1000000000
#define N 51
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

int d[N][250001];
int a[N];

// 조각을 1,2 탑에 놓거나 안 내려놓거나
// d[p][t] : p에서 시작해서 탑의 차이가 t일때 최대 같은 높이
//d[k+1][diff+a[k]], d[k+1][diff-a[k]]+a[k] (k<diff) , d[k+1][a[k]-diff]+diff (k>=diff)
int go(int i, int diff) {
	if (diff > 250000) return -INF;
	if (i == n) {
		if (diff == 0)
			return 0;
		else
			return -INF;
	}
	int& ans = d[i][diff];
	if (ans != -1) return ans;
	ans = go(i + 1, diff);
	int tmp;
	if (diff > a[i])
		tmp = go(i + 1, diff - a[i]) + a[i];
	else
		tmp = go(i + 1, a[i] - diff) + diff;
	ans = max({ ans, go(i + 1, diff + a[i]),tmp });

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(d, -1, sizeof d);
	fu(i, 0, n) {
		cin >> a[i];
	}
	cout << (go(0, 0) == 0 ? -1 : go(0, 0));
	return 0;
}