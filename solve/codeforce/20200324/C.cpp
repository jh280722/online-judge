#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1e9+9
#define MOD2 1000000021
#define INF 1e9
#define N 201
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
	string ans = "";
	cin >> n >> m >> k;
	fu(i, 0, 2*k) {
		int a, b;
		cin >> a >> b;
	}
	fu(i, 0, n-1) {
		ans += 'U';
	}
	fu(i, 0, m-1) {
		ans += 'L';
	}
	fu(i, 0, n) {
		fu(j, 0, m-1) {
			if (i%2==0) {
				ans += 'R';
			}
			else {
				ans += 'L';
			}
		}
		ans += 'D';
	}
	cout << ans.size() << '\n';
	cout << ans << '\n';
	return 0;
}