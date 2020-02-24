#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 200001
#define INF 2147000000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, k, t;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };

int alp[MAX][26];
int a[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int ans[26] = { 0 };
		cin >> n >> m;
		string s;//size n
		cin >> s;
		f(i, m) {
			cin >> a[i];
			a[i]--;
		}
		//2?10^5 
		f(i, 26) {
			alp[0][i] = 0;
		}
		alp[0][s[0] - 'a']=1;
		for (int i = 1; i < n; i++) {
			f(j, 26) {
				alp[i][j] = alp[i - 1][j];
			}
			alp[i][s[i] - 'a']++;
		}

		f(i, n) {
			ans[s[i] - 'a'] += 1;
		}
		f(i, m) {
			f(j, 26) {
				ans[j] += alp[a[i]][j];
			}
		}

		f(i, 26) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}