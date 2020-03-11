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

ll sum[100001] = { 1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vi a(n);
	f(i, 0, n)
		cin >> a[i];
	if (n > m) {
		cout << 0;
	}
	else {
		ll sum = 1;
		f(i, 0, n) {
			f(j, i+1, n) {
				sum *= abs(a[i] - a[j]);
				sum %= m;
			}
		}
		cout << sum;
	}
	return 0;
}