#include <bits/stdc++.h>
#define MAX 4097
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		set<pair<string,int>> st;
		string tmp = "";
		f(i, 0, n) {
			string a = s.substr(i);
			string b = s.substr(0, i);
			if ((n-i) % 2 == 1)
				reverse(all(b));
			st.insert({ a + b,i });
		}
		cout << st.begin()->first << '\n' << st.begin()->second +1 << '\n';
	}
	return 0;
}
