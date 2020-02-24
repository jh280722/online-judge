#include <iostream>
#include <string.h>
#include <queue>
#include <unordered_map>
#define MAX 100001
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
struct DATA {
	int day;
	int cost;
};
int d[16];
DATA co[16];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> co[i].day >> co[i].cost;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + co[i].day; j <= n; j++)
			d[j] = max(d[i] + co[i].cost, d[j]);
	}

	cout << d[n] << '\n';
	return 0;
}