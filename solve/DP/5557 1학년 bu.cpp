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

ll d[N][21];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int a;
	cin >> a;
	d[1][a] = 1;
	fu(i, 2, n) {
		int a;
		cin >> a;
		fu(j, 0, 21) {
			if (d[i - 1][j]) {
				if (j + a <= 20)
					d[i][j + a] += d[i - 1][j];
				if (j - a >= 0)
					d[i][j - a] += d[i - 1][j];
			}
		}
	}
	cin >> a;
	cout << d[n - 1][a];
	return 0;
}