#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 2147483647
typedef long long ll;
using namespace std;

struct DATA {
	int r, c;
	int dir, g;
};
int n, m, t, k;
int ans=-INF;
bool map[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };

int aidx;
int oidx;
int operand[10];
char opator[9];
bool sel[9];
void dfs( int cnt) {
	if (cnt > (n + 1) / 4) {
		return;
	}

	int result = operand[0];
	for (int i = 0; i < n/2; i++) {
		bool flag = false;
		int tmp1 = result;
		int tmp2 = operand[i + 1];
		if (sel[i+1]) {
			tmp2 = operand[i + 1];
			int tmp3 = operand[i + 2];
			switch (opator[i + 1]) {
			case '+':
				tmp2 = tmp2 + tmp3;
				break;
			case '-':
				tmp2 = tmp2 - tmp3;
				break;
			case '*':
				tmp2 = tmp2 * tmp3;
				break;
			case '/':
				tmp2 = tmp2 / tmp3;
				break;
			}
			flag = true;
		}
		switch (opator[i]) {
		case '+':
			result = tmp1 + tmp2;
			break;
		case '-':
			result = tmp1 - tmp2;
			break;
		case '*':
			result = tmp1 * tmp2;
			break;
		case '/':
			result = tmp1 / tmp2;
			break;
		}
		if (flag)
			i++;
	}
	ans = max(ans, result);

	for (int i = 0; i < n/2 ; i++) {
		if (sel[i] || (i>0 && sel[i-1])) continue;
		sel[i] = true;
		dfs(cnt + 1);
		sel[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			cin >> operand[aidx++];
		else
			cin >> opator[oidx++];
	}
	dfs(0);
	cout << ans << '\n';

	return 0;
}