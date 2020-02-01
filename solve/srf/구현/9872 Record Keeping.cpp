#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>

#define INF 2147000000
#define MAX 10
using namespace std;

int n, m;
int ans;

unordered_map<string, int> umap;
string cow[3];
int idx;
struct DATA {
	int r, c;
};
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cow[0] >> cow[1] >> cow[2];

		sort(cow, cow + 3);
		string tmp = "";
		for (int j = 0; j < 3; j++) {
			tmp += cow[j]; 
		}
		umap[tmp]++;
		ans = max(ans, umap[tmp]);
	}
	cout << ans << '\n';

	return 0;
}
