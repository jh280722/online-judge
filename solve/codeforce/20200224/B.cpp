#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 51
#define INF 2147000000
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define f(i,j) for(int i=0;i<j;i++)
using namespace std;

int n, m, k, t;
int ans = 0;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vi a(n),p(m);
		f(i, n)
			cin >> a[i];
		f(i, m)
			cin >> p[i];//a[p[i]] a[p[i]+1] swap 해서 오름차순 만들수있냐

		
		bool flag = true;
		f(i, n-1) {
			if (a[i] > a[i + 1])
				flag = false;
		}
		if (flag) {
			cout << "YES\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - (i + 1); j++) {
				if (a[j] > a[j + 1]) {
					flag = false;
					for (int k = 0; k < m; k++) {
						if (j+1 == p[k]) {
							flag = true;
							break;
						}
					}
					if (!flag) {
						break;
					}
					int temp = a[j + 1];
					a[j + 1] = a[j];
					a[j] = temp;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
		}
		else
			cout << "YES\n";
	}
	return 0;
}