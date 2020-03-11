#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#define MAX 17
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
int score[50][10];
int sel[9];
bool vis[9];
void dfs(int cnt) {
	if (cnt == 9) {
		int sum = 0; 
		int seq = 0;
		f(i, 0, n) {
			bool pos[4] = { 1,0,0,0 };
			int out = 0;
			while (out != 3) {
				pos[0] = true;
				if (score[i][sel[seq]] == 0) {
					out++;
				}
				else {
					for(int j=3;j>=0;j--) {
						if (score[i][sel[seq]] + j > 3 && pos[j]) {
							pos[j] = false;
							sum++;
						}
						else if(pos[j]){
							pos[j] = false;
							pos[j + score[i][sel[seq]]] = true;
						}
					}
				}
				seq = (seq + 1) % 9;
			}
		}
		ans = max(ans, sum);
		return;
	}
	if (cnt == 3)
		dfs(cnt + 1);
	else {
		f(i, 1, 9) {
			if (vis[i]) continue;
			sel[cnt] = i + 1;
			vis[i] = true;
			dfs(cnt + 1);
			sel[cnt] = 0;
			vis[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	f(i, 0, n) {
		f(j, 0, 9) {
			cin>>score[i][j+1];
		}
	}
	sel[3] = 1;
	vis[0] = true;
	dfs(0);
	cout << ans;
	return 0;
}