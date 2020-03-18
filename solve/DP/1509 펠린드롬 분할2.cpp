#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define pb(a,b) push_back({a,b})
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 1000000
#define INF 1000000000
#define N 2501
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
int d[N];
bool c[N];
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	n = s.size();
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = 2501;
		for (int j = 1; j <= i; j++)
		{
			if (s[j - 1] == s[i - 1] && (i - j <= 1 || c[j + 1]))
			{//i가 다음번으로 넘어가므로 s[j]==s[i]이고 c[j+1] true이면 펠린드롬이다.
				c[j] = 1;//c[j]는 c[i][j]에서 i가 순서대로 가므로 생략한 것
				if (d[i] > d[j - 1] + 1)
					d[i] = d[j - 1] + 1;
			}
			else
				c[j] = 0;
		}
	}
	cout << d[n];
	return 0;
}