#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 998244353
#define INF 1000000000
#define N 200001
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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		n = s.size();
		if (n == 1) {
			cout << s << '\n';
			continue;
		}
		int k = 0;
		fu(i, 0, n / 2) {
			if (s[i] == s[n - i - 1]) {
				k++;
			}
			else {
				break;
			}
		}
		string pre = s.substr(0, k);
		s = s.substr(k, n - 2 * k);
		n = s.size();

		int l = 0, r = n - 1;
		string mid;
		while (l <= r) {
			if (s[l] == s[r]) {
				int c = r;
				while (l < r && s[l] == s[r]) {
					l++;
					r--;
				}
				if (l >= r) {
					mid = s.substr(0, c + 1);
					break;
				}
				else {
					l = 0;
					r = c - 1;
				}
			}
			else {
				l = 0;
				r--;
			}
		}
		l = 0, r = n - 1;
		while (l <= r) {
			if (s[l] == s[r]) {
				int c = l;
				while (l < r && s[l] == s[r]) {
					l++;
					r--;
				}
				if (l >= r) {
					if (mid.size() < n - c)
						mid = s.substr(c, n);
					break;
				}
				else {
					r = n - 1;
					l = c + 1;
				}
			}
			else {
				r = n - 1;
				l++;
			}
		}
		string ans = pre + mid;
		reverse(all(pre));
		cout << ans + pre << '\n';
	}
	return 0;
}
