#include <bits/stdc++.h>
#define MAX 6
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int ans;
char Map[MAX][MAX];
int Max = -INF, Min = INF;
char sel[11];
void dfs(int idx, int cnt) {
	int r = idx / n;
	int c = idx % n;
	sel[cnt] = Map[r][c];
	if (idx == n * n - 1) {
		int s = sel[0] - '0';
		int val;
		for (int i = 2; i <= cnt; i += 2) {
			val = sel[i] - '0';
			switch (sel[i - 1]) {
			case '+': s += val; break;
			case '-': s -= val; break;
			case '*': s *= val; break;
			}
		}
		Min = min(Min, s);
		Max = max(Max, s);
		return;
	}
	if (c + 1 < n)
		dfs(idx + 1, cnt + 1);
	if (r + 1 < n)
		dfs(idx + n, cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	f(i, 0, n) {
		f(j, 0, n) {
			cin >> Map[i][j];
		}
	}
	dfs(0, 0);

	cout << Max << ' ' << Min;

	return 0;
}
