#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#define all(v) v.begin(), v.end()
#define MAX 101
#define INF 2147483647
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };
struct Team {
	bool sol[16];
	int num;
	int solnum;
	int score;
	int penalty[16];
}team[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int q;
	cin >> q;
	for (int i = 1; i <= n; i++) {
		team[i].num = i;
	}
	for (int i = 0; i < q; i++) {
		int time, tn, mn;
		string result;
		cin >> time >> tn >> mn >> result;
		if (result == "AC") {
			if (team[tn].sol[mn]) continue;
			team[tn].sol[mn] = true;
			team[tn].score += time + team[tn].penalty[mn];
			team[tn].solnum++;
		}
		else {
			team[tn].penalty[mn] += 20;
		}
	}
	sort(team+1, team + 1 + n, [](Team a, Team b) {
		if (a.solnum != b.solnum)
			return a.solnum > b.solnum;
		else if (a.solnum == b.solnum && a.score != b.score)
			return a.score < b.score;
		else 
			return a.num < b.num; 
		});
	for (int i = 1; i <= n; i++) {
		cout << team[i].num << ' ' << team[i].solnum << ' ' << team[i].score << '\n';
	}
	return 0;
}