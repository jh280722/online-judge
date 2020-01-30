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
	int num;
	char alp;
};
string word[10];
DATA cnt[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	for (int i = 0; i < 26; i++) {
		cnt[i].alp = i + 'A';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < word[i].size(); j++) {
			cnt[word[i][j] - 'A'].num += pow(10, word[i].size()-j -1);
		}
	}
	sort(cnt, cnt + 26, [](DATA a, DATA b) {return a.num > b.num; });
	for (int i = 0; i < 10; i++) {
		if (cnt[i].num) {
			cnt[i].num *= 9 - i;
		}
	}

	for (int j = 0; j < 10; j++) {
		if (cnt[j].num) {
			ans += cnt[j].num;
		}
	}

	cout << ans << '\n';

	return 0;
}