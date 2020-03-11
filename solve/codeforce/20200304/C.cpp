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
	//ans <= n+m-2 ����� p�� �����������ʴ� ���� ���
	//�� ���׽��� ����� ���ؾ��Ѵ�.
	//gcd(a) == gcd(b)==1
	//��� �Ҽ��̹Ƿ� p�� ������� 1�̴�. ����� p�϶� �����
	//�ᱹ ����� ��������� �̷�����͸� �ش��̵ȴ�.
	//�� ó������ ����� p�� �������� ���ϸ� ���� ����� p*���� ���°� �ƴ϶��
	//P�� ���������ʴ´�. ���� P�� ������ ���� ����϶��� �ε����� ���̸鼭 ���ϸ� �ȴ�.
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
