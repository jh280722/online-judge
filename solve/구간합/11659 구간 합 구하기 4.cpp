#include <iostream>
#include <string.h>
#include <queue>
#include <unordered_map>
#define MAX 101
#define INF 214700000
#define pii pair<int,int>
#define ll long long
using namespace std;

int n, m, k, t, a, ans = 0;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
int sum[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sum[i+1] += sum[i]+tmp;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << '\n';
	}
	return 0;
}