#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, string> d;
	cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string site,password;
        cin>>site>>password;
        d[site]=password;
    }
    for(int i = 0; i < m; i++) {
        string a;
        cin >> a;
        cout<<d[a]<<'\n';
    }

	return 0;
}
