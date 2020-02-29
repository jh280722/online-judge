#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,cnt;
set<string> s;
set<string> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        s.insert(a);
    }
    for(int i = 0; i < m; i++) {
        string a;
        cin >> a;
        if(s.count(a)) {
            cnt++;
            v.insert(a);
        }
    }
    cout << cnt << '\n';
    for(auto it = v.begin(); it != v.end(); it++) cout << *it << '\n';

	return 0;
}
