#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define MOD 100000
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
int a[N];
int x[N];
int b[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int Max = 0;
	fu(i, 0, n) {//b[i] = a[i]-x[i]
		cin >> b[i];
		a[i] = b[i] + x[i];
		if (x[i] < a[i])
			x[i + 1] = a[i];
		else
			x[i + 1] = x[i];
	}
	//b[i]+x[i]
	fu(i, 0, n) {
		cout << b[i] + x[i] << ' ';
	}
	return 0;
}