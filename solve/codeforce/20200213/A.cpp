#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
#include <set>
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define MAX 2001
#define INF 2147483640
typedef long long ll;
using namespace std;

int n, m, t, k;
int ans = 0;
int dr[] = { 0,-1,0,1 };
int dc[] = { 1,0,-1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		string a, b, c;
		cin >> a >> b >> c;
		bool ch = false;
		for (int i = 0; i < b.size(); i++) {
			if ((b[i] == a[i] && b[i] == c[i])|| (b[i] != a[i] && b[i] == c[i] ) || (b[i]!=a[i] &&  a[i]==c[i] ))
				continue;
			else {
				ch = true;
				break;
			}
		}
		if (ch)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
	return 0;
}