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
int ans;
int Max = -INF, Min = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		ans = 1;
		string s;
		cin >> s;
		n = s.size();
		int d = 1;
		fu(i, 0, n) {
			if (s[i] == 'L') {
				d++;
				ans = max(ans, d);
			}
			else if (s[i] == 'R') {
				d = 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
