#include <bits/stdc++.h>

#define MAX 102
#define INF 2147000000
#define ll long long
using namespace std;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };

int t;
int n, m, p, k, l, ans;

struct DATA {
	int r,c;
};
DATA arr[12];
string map1[5];
int cnt;
bool check[12];
bool flag = 0;
void dfs(int idx, int num) {

	if (num == cnt)
	{
		if (map1[0][4] + map1[1][3] + map1[2][2] + map1[3][1] - 4 * 'A' + 4 != 26) return;
		if (map1[0][4] + map1[1][5] + map1[2][6] + map1[3][7] - 4 * 'A' + 4 != 26) return;
		if (map1[3][1] + map1[3][3] + map1[3][5] + map1[3][7] - 4 * 'A' + 4 != 26) return;
		if (map1[1][1] + map1[1][3] + map1[1][5] + map1[1][7] - 4 * 'A' + 4 != 26) return;
		if (map1[1][1] + map1[2][2] + map1[3][3] + map1[4][4] - 4 * 'A' + 4 != 26) return;
		if (map1[1][7] + map1[2][6] + map1[3][5] + map1[4][4] - 4 * 'A' + 4 != 26) return;
		flag = true;
		return;
	}

	for (int i = 0; i < 12; i++) {
		if (!check[i]) {
			check[i] = true;
			map1[arr[idx].r][arr[idx].c] = i + 'A';
			dfs(idx + 1, num + 1);
			if (flag)
				return;
			map1[arr[idx].r][arr[idx].c] = 'x';
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++)
	{
		cin >> map1[i];
		for (int j = 0; j < 9; j++)
		{
			if ('A' <= map1[i][j] && map1[i][j] <= 'L') check[map1[i][j] - 'A'] = true;
			if (map1[i][j] == 'x') { arr[cnt].c = j; arr[cnt].r = i; cnt++; }
		}
	}
	dfs(0, 0);
	for (int i = 0; i < 5; i++) {
		cout << map1[i] << '\n';
	}
	return 0;
}