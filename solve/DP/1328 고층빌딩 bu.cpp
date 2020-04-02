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

ll d[N][N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, l;
	cin >> n >> l >> r;
	d[1][1][1] = 1;
	fu(i, 2, n + 1) {
		fu(L, 1, l + 1) {
			fu(R, 1, r + 1) {
				d[i][L][R] = d[i - 1][L - 1][R] + d[i - 1][L][R - 1] + d[i - 1][L][R] * (i - 2);
				d[i][L][R] %= MOD;
			}
		}
	}
	cout << d[n][l][r];
	return 0;
}