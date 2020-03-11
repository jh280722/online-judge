#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#define MAX 16
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
int d;
int Map[MAX][MAX];
bool vis[MAX][MAX];
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };
int archer[3];
//d만큼 거리 찾아서 왼쪽 우선
struct MON {
	bool exist;
	int r, c;
};
vector<MON> mon;
vector<MON> tmp;

int dis(MON mon, int archer) {
	return abs(mon.r - n) + abs(mon.c - archer);
}
void dfs(int idx, int cnt) {
	if (cnt == 3) {
		mon = tmp;
		int sz = mon.size();
		sort(all(mon), [](MON a, MON b) {if (a.c == b.c) return a.r > b.r; else return a.c < b.c; });
		int score = 0;
		while (sz) {
			int idx[3] = { -1,-1,-1 };
			pii LH[3];
			f(i, 0, 3) {
				bool flag = false;
				LH[i].first = n, LH[i].second = archer[i];
				f(k, 1, d + 1) {
					f(j, 0, sz) {
						if (dis(mon[j], archer[i]) <= k) {
							mon[j].exist = false;
							flag = true;
							break;
						}
					}
					if (flag)
						break;
				}
			}
			f(i, 0, sz)
				mon[i].r++;
			f(i, 0, sz) {
				if (!mon[i].exist) {
					mon.erase(mon.begin() + i);
					sz--;
					i--;
					score++;
				}
				else if (mon[i].r == n) {
					mon.erase(mon.begin() + i);
					i--;
					sz--;
				}
			}
		}
		ans = max(ans, score);
		return;
	}

	f(i, idx, m) {
		archer[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> d;
	f(i, 0, n)
		f(j, 0, m) {
		cin >> Map[i][j];//1 적 
		if (Map[i][j]) {
			tmp.push_back({ true, i,j });
		}
	}
	dfs(0, 0);

	cout << ans;
	return 0;
}