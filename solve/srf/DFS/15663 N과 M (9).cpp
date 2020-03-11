#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#define MAX 4097
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

int n, m, k, t;
int ans;
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };

vi a;
int sel_val[9];
bool sel[9]; 
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << sel_val[i] << ' ';
		}
		cout<<'\n';
		return;
	}
	int before = 0;
	f(i, 0, n) {
		if (sel[i]) continue;
		if (i && before == a[i]) continue;
		before = a[i];
		sel[i] = true;
		sel_val[cnt] = a[i];
		dfs(i + 1, cnt + 1);
		sel[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	f(i, 0, n) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	sort(all(a));
	dfs(0, 0);
	return 0;
}