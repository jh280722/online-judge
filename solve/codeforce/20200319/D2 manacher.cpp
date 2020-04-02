#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000009
#define MOD2 1000000021
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

int a[2000005];

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
		string tmp = "#";
		fu(i, 0, n) {
			tmp += s[i];
			tmp += '#';
		}
		s = tmp;
		n = s.size();
		fu(i, 0, n) {
			a[i] = 0;
		}
		int r = 0, p = 0;
		for (int i = 1; i < n; i++) {
			if (i <= r)
				a[i] = min(a[2 * p - i], r - i);
			while (i - a[i] - 1 >= 0 && i + a[i] + 1 < n &&
				s[i - a[i] - 1] == s[i + a[i] + 1]) a[i]++;
			if (r < i + a[i])
				r = i + a[i], p = i;
		}
		int res = 0, idx = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] == i || a[i] == n - i - 1)
			{
				if (res < a[i])
				{
					res = a[i];
					idx = i;
				}
			}
		}
		for (int i = idx - res + (s[idx - res] == '#' ? 1 : 0); i < idx; i += 2)
			pre += s[i];
		string mid;
		if (s[idx] != '#')
			mid = s[idx];

		string ans = pre + mid;
		reverse(all(pre));
		cout << ans + pre << '\n';
	}
	return 0;
}
