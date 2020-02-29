#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 2147000000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
	using namespace std;

int n, m, k, t;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
int map[MAX][MAX];
int ans;
pii cnt[101];
void r_oper() {
	f(i, n) {
		memset(cnt, 0, sizeof(cnt));
		int lng = 0;
		f(j, m) {
			if (map[i][j] == 0) continue;
			if (cnt[map[i][j]].first == 0)
				lng++;
			cnt[map[i][j]].first++;
			cnt[map[i][j]].second = map[i][j];
		}
		sort(cnt, cnt + 101);
		f(j,lng) {
			if (2 * j >= 100) {
				m = 100;
				break;
			}
			map[i][2*j] = cnt[101 - lng + j].second;
			map[i][2*j+1] = cnt[101 - lng + j].first;
		}
		for (int j = 2 * lng; j < m; j++) {
			map[i][j] = 0;
		}
		m = max(m, lng * 2);
	}
}

void c_oper() {
	f(j, m) {
		memset(cnt, 0, sizeof(cnt));
		int lng = 0;
		f(i, n) {
			if (map[i][j] == 0) continue;
			if (cnt[map[i][j]].first == 0)
				lng++;
			cnt[map[i][j]].first++;
			cnt[map[i][j]].second = map[i][j];
		}
		sort(cnt, cnt + 101);
		f(i, lng) {
			if (2 * i >= 100) {
				n = 100;
				break;
			}
			map[2*i][j] = cnt[101 - lng + i].second;
			map[2*i+1][j] = cnt[101 - lng + i].first;
		}
		for (int i = 2 * lng; i < n; i++) {
			map[i][j] = 0;
		}
		n = max(n,lng * 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, c;
	cin >> r >> c >> k;
	n = 3, m = 3;
	f(i, n) {
		f(j, m) {
			cin >> map[i][j];
		}
	}

	while (ans <= 100) {
		if (map[r-1][c-1] == k) {
			break;
		}
		if (n >= m) {
			r_oper();
		}
		else {
			c_oper();
		}
		ans++;
	}
	if (ans > 100)
		ans = -1;
	cout << ans << '\n';

	return 0;
}