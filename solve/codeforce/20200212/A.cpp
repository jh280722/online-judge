#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };
int map[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int j = 0;
		bool flag = false;
		int cnt = 0;
		int ans = 0;
		while(j<s.size()) {
			if (flag && s[j] == '0')
				cnt++;
			if (!flag && s[j] == '1')
				flag = true;
			else if (flag && s[j] == '1') {
				ans += cnt;
				cnt = 0;
			}
			j++;
		}
		cout << ans << '\n';
	}
	return 0;
}