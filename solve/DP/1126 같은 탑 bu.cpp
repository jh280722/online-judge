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

int d[2][500001];
int a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int sum = 0;
	memset(d, -1, sizeof d);
	d[0][0] = 0;
	fu(i, 0, n) {
		cin >> a[i];
	}
	sort(a, a + n);
	d[0][0] = d[1][0] = 0;
	fu(i, 0, n) {
		fu(j, 0, sum + 1) {
			if (d[0][j] == -1) continue;
			if (j - a[i] >= 0) {
				if (d[0][j] > d[1][j - a[i]])
					d[1][j - a[i]] = d[0][j];
			}
			else
			{
				int t = d[0][j] + a[i] - j;
				if (t > d[1][a[i] - j])
					d[1][a[i] - j] = t;
			}
			int t = d[0][j] + a[i];
			if (t > d[1][j + a[i]])
				d[1][j + a[i]] = t;
		}
		sum += a[i];
		fu(j, 0, sum + 1) {
			d[0][j] = d[1][j];
		}
	}
	cout << (d[0][0] ? d[0][0] : -1);
	return 0;
}