#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>

#define INF 2147000000
#define MAX 15
using namespace std;

struct DATA {
	int r, c;
};

vector<pair<string,int>> dict;

int n, m, k;
int ans = 0;
bool m_strstr(string str,string src) {
	int i = 0,j = 0;
	while (str[i++] == src[j++]);
	if (src[j-1] == 0)
		return true;
	else
		return false;
}

bool match(string pre, string word) {
	if (pre.size() > word.size()) return false;
	return word.substr(0, pre.size()) == pre;
}

int bs(string pre) {
	int low = 0, hi = n;
	while (low + 1 < hi) {
		int mid = (low + hi - 1) / 2;
		if (dict[mid].first < pre) {
			low = mid + 1;
		}
		else {
			hi = mid + 1;
		}
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		dict.push_back({ s,i+1 });
	}
	sort(dict.begin(), dict.end());
	for (int i = 0; i < m; i++) {
		int index;
		string tmp;
		cin >> index >> tmp;
		index--;
		int low=bs(tmp);

		if (low + index < dict.size() && match(tmp, dict[low+index].first))
			cout << dict[low+index].second << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}
