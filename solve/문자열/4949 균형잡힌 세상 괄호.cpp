#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fu(i,a,j) for(int i=a;i<j;i++)
#define fd(i,a,j) for(int i=a;i>=j;i--)
#define SYNC ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1e9+9
#define MOD2 1000000021
#define INF 1e9
#define N 51
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
int main() {
	SYNC;
	while (true) {
		string s;
		getline(cin, s, '\n');
		if (s == ".")
			break;
		bool y = true;
		stack<char> s1;
		fu(i, 0, s.size()) {
			if (s[i] == '(' || s[i] == '[') {
				s1.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']') {
				if (s1.empty()) {
					y = false;
					break;
				}
				else if ((s1.top() == '(' && s[i] == ')') || (s1.top() == '[' && s[i] == ']'))
					s1.pop();
				else {
					y = false;
					break;
				}
			}
		}
		if (!s1.empty())
			y = false;
		if (y)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}