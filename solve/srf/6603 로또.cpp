#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
	int cnt;
};

const int MAX = 101;
const int INF = 2147000000;
char map1[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;
int v[50];
bool visit1[50];
void dfs(int idx, int cnt) {

	if (cnt == 6) {
		for (int i = 0; i < n; i++) {
			if (visit1[i])
				cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx+1; i < n; i++) {
		visit1[i] = true;
		dfs(i, cnt + 1);
		visit1[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> n;
		if (!n)
			break;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		dfs(-1, 0);
		cout << '\n';
	}

	return 0;
}