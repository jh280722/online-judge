#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
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
int ans[1001];
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	stack<int> st;
	vi idx[1001];
	int k = 0;
	while (true) {
		int sz = s.size();
		while (!st.empty())
			st.pop();
		int tmp = ans[k];
		bool flg = false;
		for (int i = 0; i < sz; i++) {
			if (s[i] == ')') {
				st.push(i);
			}
		}
		f(i, 0, sz) {
			if (s[i] == '(' && !st.empty() && i < st.top()) {
				idx[k].push_back(i + 1);
				idx[k].push_back(st.top() + 1);
				ans[k] += 2;
				st.pop();
			}
			if (!st.empty() && i >= st.top()) {
				st.pop();
			}
			if (st.empty())
				break;
		}
		if (tmp == ans[k]) {
			break;
		}
		sort(all(idx[k]));
		f(i, 0, idx[k].size()) {
			s.erase(s.begin() + (idx[k][i] - i - 1));
		}
		k++;
	}
	if (k != 0) {
		cout << k << '\n';
		cout << ans[k - 1] << '\n';
		f(i, 0, idx[k - 1].size()) {
			cout << idx[k - 1][i] << ' ';
		}
	}
	else {
		cout << 0 << '\n';
	}
	return 0;
}