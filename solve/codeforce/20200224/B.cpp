#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <iomanip>
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
int a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}
		//인접한 배열의 최소 차이 그 차이값 출력
		int k = 0;
		ll sum = 0;
		int cnt = 0;
		bool ch = false;
		int mi=1000000000, ma=0;
		for (int i = 0; i < n - 1; i++) {
			if ((a[i] != -1 && a[i+1] == -1)) {
				if (mi > a[i])
					mi = a[i];
				if (ma < a[i])
					ma = a[i];
			}
			if ((a[i + 1] != -1 && a[i] == -1)) {
				if (mi > a[i+1])
					mi = a[i+1];
				if (ma < a[i+1])
					ma = a[i+1];
			}
		}	
		sum = mi + ma;
		sum /= 2;
		if(sum==0) {
			for (int i = 0; i < n; i++) {
				if (a[i] == -1)continue;
				sum +=a[i];
				cnt++;
			}
			if (cnt == 0)
				cnt = 1;
			sum /= cnt;
		}
		for (int i = 0; i < n - 1; i++) {
			if (a[i] == -1)
				a[i] = sum;
			if (a[i+1] == -1)
				a[i+1] = sum;
			ans = max(ans, abs(a[i + 1] - a[i]));
		}
		cout << ans << ' ' << sum << '\n';
	}
	return 0;
}