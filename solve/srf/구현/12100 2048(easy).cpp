#include <iostream>
#include <string.h>
#include <queue>
#define MAX 21
#define INF 214700000
typedef long long ll;
using namespace std;

int n, m, t, ans;
int map[MAX][MAX];
int tmp[MAX][MAX];

struct DATA {
	int r, c;
};

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };

int sel_dir[5];
void sim() {
	int result = 0;
	for (int k = 0; k < 5; k++) {
		switch (sel_dir[k]) {
		case 0://오른쪽으로
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					int idx = j;
					if (tmp[i][j] != 0) {
						idx--;
						while (idx > 0 && tmp[i][idx] == 0) {
							idx--;
						}
						if (idx < 0 || tmp[i][idx] == 0)
							break;
						if (tmp[i][j] == tmp[i][idx]) {
							tmp[i][j] += tmp[i][idx];
							if (idx != j)
								tmp[i][idx] = 0;
						}
					}
					else {
						while (idx > 0 && tmp[i][idx] == 0) {
							idx--;
						}
						if (idx < 0 || tmp[i][idx] == 0)
							break;
						int idx2 = idx - 1;
						if (idx2 < 0) {
							tmp[i][j] = tmp[i][idx];
							tmp[i][idx] = 0;
							break;
						}
						while (idx2 > 0 && tmp[i][idx2] == 0) {
							idx2--;
						}
						if (tmp[i][idx] == tmp[i][idx2]) {
							tmp[i][j] = tmp[i][idx] + tmp[i][idx2];
							if (idx != j)
								tmp[i][idx] = 0;
							tmp[i][idx2] = 0;
						}
						else {
							tmp[i][j] = tmp[i][idx];
							tmp[i][idx] = 0;
						}
					}
				}

			}
			break;
		case 1://아래
			for (int j = n - 1; j >= 0; j--) {
				for (int i = n - 1; i >= 0; i--) {
					int idx = i;
					if (tmp[i][j] != 0) {
						idx--;
						while (idx > 0 && tmp[idx][j] == 0) {
							idx--;
						}
						if (idx < 0 || tmp[idx][j] == 0)
							break;
						if (tmp[i][j] == tmp[idx][j]) {
							tmp[i][j] += tmp[idx][j];
							if (idx != i)
								tmp[idx][j] = 0;
						}
					}
					else {

						while (idx > 0 && tmp[idx][j] == 0) {
							idx--;
						}
						if (idx < 0 || tmp[idx][j] == 0)
							break;
						int idx2 = idx - 1;
						while (idx2 > 0 && tmp[idx2][j] == 0) {
							idx2--;
						}
						if (idx2 < 0) {
							tmp[i][j] = tmp[idx][j];
							tmp[idx][j] = 0;
							break;
						}
						if (tmp[idx][j] == tmp[idx2][j]) {
							tmp[i][j] = tmp[idx][j] + tmp[idx2][j];
							tmp[idx][j] = 0;
							tmp[idx2][j] = 0;
						}
						else {
							tmp[i][j] = tmp[idx][j];
							tmp[idx][j] = 0;
						}
					}
				}
			}
			break;
		case 2://왼
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < n; j++) {
					int idx = j;

					if (tmp[i][j] != 0) {
						idx++;
						while (idx < n - 1 && tmp[i][idx] == 0) {
							idx++;
						}
						if (idx >= n || tmp[i][idx] == 0)
							break;
						if (tmp[i][j] == tmp[i][idx]) {
							tmp[i][j] += tmp[i][idx];
							if (idx != j)
								tmp[i][idx] = 0;
						}
					}
					else {
						while (idx < n - 1 && tmp[i][idx] == 0) {
							idx++;
						}
						if (idx >= n || tmp[i][idx] == 0)
							break;
						int idx2 = idx + 1;
						while (idx2 < n - 1 && tmp[i][idx2] == 0) {
							idx2++;
						}
						if (idx2 >= n) {
							tmp[i][j] = tmp[i][idx];
							tmp[i][idx] = 0;
							break;
						}
						if (tmp[i][idx] == tmp[i][idx2]) {
							tmp[i][j] = tmp[i][idx] + tmp[i][idx2];
							tmp[i][idx] = 0;
							tmp[i][idx2] = 0;
						}
						else {
							tmp[i][j] = tmp[i][idx];
							tmp[i][idx] = 0;
						}
					}

				}
			}
			break;
		case 3://위
			for (int j = 0; j < n; j++) {
				for (int i = 0; i < n; i++) {
					int idx = i;
					if (tmp[i][j] != 0) {
						idx++;
						while (idx < n - 1 && tmp[idx][j] == 0) {
							idx++;
						}
						if (idx >= n || tmp[idx][j] == 0)
							break;
						if (tmp[i][j] == tmp[idx][j]) {
							tmp[i][j] += tmp[idx][j];
							if (idx != i)
								tmp[idx][j] = 0;
						}
					}
					else {
						while (idx < n - 1 && tmp[idx][j] == 0) {
							idx++;
						}
						if (idx >= n || tmp[idx][j] == 0)
							break;
						int idx2 = idx + 1;
						while (idx2 < n - 1 && tmp[idx2][j] == 0) {
							idx2++;
						}
						if (idx2 >= n) {
							tmp[i][j] = tmp[idx][j];
							tmp[idx][j] = 0;
							break;
						}
						if (tmp[idx][j] == tmp[idx2][j]) {
							tmp[i][j] = tmp[idx][j] + tmp[idx2][j];
							tmp[idx][j] = 0;
							tmp[idx2][j] = 0;
						}
						else {
							tmp[i][j] = tmp[idx][j];
							tmp[idx][j] = 0;
						}
					}

				}
			}
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < tmp[i][j])
				ans = tmp[i][j];
		}
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		memcpy(tmp, map, sizeof(tmp));
		sim();
		return;
	}
	for (int i = 0; i < 4; i++) {
		sel_dir[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}