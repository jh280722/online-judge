#include <iostream>
#include <queue>
#include <algorithm>

#define INF 2147000000
#define MAX 10
using namespace std;

int n, m;
int ans;

struct DATA {
	int r, c;
};
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int cow[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cow[i];
	}
	cow[n] = INF;
	sort(cow, cow + n+1);

	for (int i = 0; i < n-2; i++) {
		int s = i + 2; int e = i + 2;
		for (int j = i+1; j < n - 1; j++) {
			while(1) {
				if (cow[s] - cow[j] >= cow[j] - cow[i]) break;
				s++;
			}
			if (e < s) e = s;
			while (1) {
				if (cow[e] - cow[j] > (cow[j] - cow[i]) * 2) break;
				e++;
			}
			ans += e - s;
		}
	}
	cout << ans << '\n';
	return 0;
}
