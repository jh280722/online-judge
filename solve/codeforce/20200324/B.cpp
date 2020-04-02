#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1e9+9
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
int dr[] = { 1,0,-1,0, -1,1,1,-1 };
int dc[] = { 0,1,0,-1, 1,1,-1,-1 };

vi a[N];
bool c[N];
bool c2[N];
bool da[N];

int main() {
	SYNC;
	cin >> t;
	while (t--) {
		int idx = 0;
		int pr = 0;
		cin >> n;
		fu(i, 1, n+1) {
			a[i].clear();
			c[i] = 0;
			c2[i] = 0;
			da[i] = 0;
		}
		fu(i, 1, n+1) {
			bool flg = false;
			int listn;
			cin >> listn;
			fu(j, 0, listn) {
				int tmp;
				cin >> tmp;
				if (!flg && !c[tmp]) {
					c[tmp] = 1;
					da[i] = 1;
					flg = true;
				}
				else if(!flg) {
					a[i].push_back(tmp);
				}
			}
			if (!flg && idx==0)
				idx = i;
		}
		fu(i, 0, a[idx].size()) {
			if (!c[a[idx][i]])
				c[a[idx][i]] = 1;
		}
		fu(i, 1, n + 1) {
			if (!c[i]) {
				pr = i;
				break;
			}
		}
		if (pr == 0) {
			cout << "OPTIMAL\n";
		}
		else {
			cout << "IMPROVE\n";
			cout << idx << ' ' << pr << '\n';
		}
	}
	return 0;
}