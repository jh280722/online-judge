#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DATA {
	int x, y;
};

const int MAX = 301;
const int INF = 2147000000;
bool visit[MAX][MAX];
int a[22];
int dr[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dc[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int t;
int n, m, p, k, l, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll num;
	int m, n;
	cin >> n >> m;
	if (m == 1)
	{
		cin >> num;
		num--;
		for (int i = n - 1; i >= 0; i--)
		{
			a[i] = num % (n - i) + 1;
			num /= n - i;
			for (int j = i + 1; j < n; j++) {
				if (a[j] >= a[i])
					a[j]++;
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i]<<' ';
	}
	else
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		num = 0;
		for (int i = 0; i < n; i++)
		{
			num *= n - i;
			for (int j = i + 1; j < n; j++) {
				if (a[j] < a[i])
					num++;
			}
		}
		cout << num + 1 << '\n';
	}

	return 0;
}