#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#include <stack>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };

int visit[26];
string ans = "";

void dfs(int v, bool alp[][26]) {
	visit[v] = true;
	for (int i = 0; i < 26; i++) {
		if (alp[v][i] && !visit[i]) {
			dfs(i, alp);
		}
	}
	ans += v + 'a';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		string s;
		ans = "";
		cin >> s;
		bool alp[26][26];
		int alpcnt[26];
		memset(alp, 0, sizeof(alp));
		memset(alpcnt, 0, sizeof(alpcnt));
		memset(visit, 0, sizeof(visit));
		int N = s.size();
		for (int i = 0; i < N - 1; i++)
		{
			alp[s[i] - 'a'][s[i + 1] - 'a'] = true;
			alp[s[i+1] - 'a'][s[i] - 'a'] = true;
		}
		bool no = false;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (alp[i][j])
					alpcnt[i]++;
				if (alpcnt[i] > 2) {
					no = true;
					break;
				}
			}
			if (no)
				break;
		}
		if (no) {
			cout << "NO\n";
			continue;
		}
		for (int i = 0; i < 26; i++) {
			if (!visit[i] && alpcnt[i] == 1) {
				dfs(i,alp);
			}
		}
		for (int i = 0; i < 26; i++) {
			if (!visit[i] && alpcnt[i]) {
				no = true;
				break;
			}
			if(!visit[i])
				ans += i + 'a';
		}
		if (no)
			cout << "NO\n";
		else
			cout << "YES\n" << ans << '\n';
	}
	return 0;
}