#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 998244353
#define MOD2 1000000021
#define INF 1e9
#define N 100001
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

int main() {
	SYNC;
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		string ans;
		int odd = 0;
		fu(i, 0, n) {
			if ((s[i] - '0') % 2 == 1) {
				odd++;
				ans += s[i];
			}
			if (odd == 2) break;
		}
		if (odd != 2) {
			cout << -1 << '\n';
			continue;
		}
		cout << ans << '\n';
	}
	return 0;
}


