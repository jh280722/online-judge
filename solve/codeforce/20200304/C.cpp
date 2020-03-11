#include <bits/stdc++.h>
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int p;
	cin >> n >> m >> p;
	vi a(n), b(m);
	f(i, 0, n)
		cin >> a[i];
	f(i, 0, m)
		cin >> b[i];
	//ans <= n+m-2 계수가 p로 나누어지지않는 차수 출력
	//두 다항식의 계수를 구해야한다.
	//gcd(a) == gcd(b)==1
	//모두 소수이므로 p와 공약수가 1이다. 계수가 p일때 말고는
	//결국 계수가 계수합으로 이루어진것만 해당이된다.
	//맨 처음부터 계수가 p라서 다음것을 비교하면 다음 계수도 p*알파 형태가 아니라면
	//P로 나눠지지않는다. 따라서 P로 나누어 지는 경우일때만 인덱스를 높이면서 비교하면 된다.
	int l = 0, r = 0;
	for (int i = 0; i < n + m - 1; i++)
	{
		if (a[l] % p == 0) l++;
		else if (b[r] % p == 0) r++;
		else
		{
			cout << i;
			return 0;
		}
	}

	return 0;
}
