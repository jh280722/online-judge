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
int ans;
vi pn;
void Eratos(int n) {
	vector < bool> PrimeArray(n+1,true);
	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}
	f(i, 2, n+1) {
		if (PrimeArray[i])
			pn.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	Eratos(n);
	
	int sum = 0;
	int s = 0;

	f(i, 0, pn.size()) {
		sum += pn[i];
		while (sum > n)
			sum -= pn[s++];
		ans += sum == n;
	}

	cout << ans;

	return 0;
}
