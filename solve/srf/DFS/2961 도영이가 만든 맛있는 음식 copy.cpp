#include <bits/stdc++.h>

#define MAX 9
#define INF 2147000000
#define ll long long
using namespace std;

int dr[] = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };
int dc[] = { 0, 1, 0, -1, 1, -1, 1, -1, 0 };

int t;
int n, m, p, k, l;
ll ans = INF;

struct DATA {
	int r, c;
};

string map2[MAX];
//int visit[MAX][MAX];

bool visit[10];
ll s[10], b[10];
queue<DATA> q;

ll mult = 1, sum = 0;

void dfs(int cnt, int ss, int bb) {

	if (ans == 0) {
		return;
	}
	if (bb > 0) {
		ll sub = abs(ss - bb);
		ans = ans < sub ? ans : sub;
	}
	if (cnt == n + 1)
		return;
	dfs(cnt + 1, ss, bb);
	dfs(cnt + 1, ss * s[cnt], bb + b[cnt]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> b[i];
	}
	dfs(0, 1, 0);
	cout << ans << '\n';
	return 0;
}