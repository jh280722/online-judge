#include <bits/stdc++.h>
#define MAX 1001
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0, 1, -1, 0, 0 };
int dc[] = { 0, 0, 0, -1, 1 };
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	string s;
	cin >> s;
	int on=0, cn = 0;
	f(i, 0, n) {
		if (s[i] == '(')
			on++;
		else
			cn++;
	}
	if (on != cn) {
		cout << -1;
	}
	else {
		bool flg = false;
		ans = 0;
		on = 0; cn = 0;
		int si = 0;
		f(i, 0, n) {
			if (on>cn && s[i] == ')') {
				on--;
			}
			else if(on<=cn && s[i]==')'){
				cn++;
				ans++;
			}
			if (on < cn && s[i] == '(') {
				cn--;
				ans++;
			}
			else if (on >= cn && s[i] == '(') {
				on++;
			}
		}
		cout << ans;
	}
	return 0;
}
