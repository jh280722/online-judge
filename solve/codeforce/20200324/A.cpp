#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1e9+9
#define MOD2 1000000021
#define INF 1e9
#define N 2000001
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

int a[N];

int main() {
	SYNC;
	cin >> t;
	ll n, k;
	while (t--) {
		cin >> n >> k;
		if (k % 2 == 0) {
			if (n % 2 != 0) {
				cout << "NO\n";
				continue;
			}
			else {
				if (n < k * k) {
					cout << "NO\n";
					continue;
				}
				else {
					cout << "YES\n";
					continue;
				}
			}
		}
		else {
			if (n % 2 == 0) {
				cout << "NO\n";
				continue;
			}
			else {
				if (n < k * k) {
					cout << "NO\n";
					continue;
				}
				else {
					cout << "YES\n";
					continue;
				}
			}
		}
	}
	return 0;
}