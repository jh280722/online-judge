#include <iostream>
#include <queue>
#define MAX 101
#define INF 1000000001 //ÇÊ¼ö
typedef long long ll;
using namespace std;

int n, t, ans;

int opand[11];
int num_opator[4];//+ - * /

int max_num = -INF, min_num = INF;
void dfs(int num_opator[], int cnt, int val) {
	if (cnt == n) {
		max_num = max(max_num, val);
		min_num = min(min_num, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (num_opator[i] > 0) {
			num_opator[i] --;
			switch (i) {
			case 0:
				dfs(num_opator, cnt + 1, val + opand[cnt]);
				break;
			case 1:
				dfs(num_opator, cnt + 1, val - opand[cnt]);
				break;
			case 2:
				dfs(num_opator, cnt + 1, val * opand[cnt]);
				break;
			case 3:
				dfs(num_opator, cnt + 1, val / opand[cnt]);
				break;
			}
			num_opator[i] ++;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> opand[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> num_opator[i];
	}

	dfs(num_opator, 1, opand[0]);
	cout << max_num << '\n' << min_num << '\n';
	return 0;
}