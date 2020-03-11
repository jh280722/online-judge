#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
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
int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		int x, y;
		cin >> m >> n;
		cin >> x >> y;
		int xx = x, yy = y;
		while(xx<=m*n && yy<=n*m) {
			if (xx == yy)
				break;
			while (xx < yy)
				xx += m;
			while (yy < xx)
				yy += n;
		}
		if (xx == yy)
			cout << xx << '\n';
		else
			cout << -1 << '\n';
	}

	return 0;
}
