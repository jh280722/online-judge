#include <bits/stdc++.h>
#define MAX 501
#define MOD 1000000
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m, k, t;
int dr[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dc[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int Max = -INF, Min = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vi a(n), b(n), dif(n);
	fu(i, 0, n) {
		cin >> a[i];
	}
	fu(i, 0, n) {
		cin >> b[i];
		dif[i] = a[i] - b[i];
	}
	sort(all(dif));
	ll ans = 0;
	fu(i, 0, n) {
		int c = n - (upper_bound(dif.begin() + i + 1, dif.end(), -dif[i]) - dif.begin());
		ans += c;
	}
	cout << ans;
	return 0;
}
