#include <bits/stdc++.h>
#define MAX 6
#define INF 1000000000
#define all(v) v.begin(), v.end()
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vii vector<ll>
#define f(i,a,j) for(int i=a;i<j;i++)
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, m, k, t;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int ans;
int Max = -INF, Min = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string> s;
		string decode, incode;
		char alp[26];
		bool chk[26];
		bool sel[26] = { 0 };
		char de[26];
		int cnt = 0;
		bool ok = 0;
		memset(de, 0, sizeof de);
		f(i, 0, n) {
			string tmp;
			cin >> tmp;
			s.push_back(tmp);
		}
		cin >> decode;
		cin >> incode;
		f(i, 0, n) {
			if (decode.size() != s[i].size()) continue;
			bool flg = true;
			memset(alp, 0, sizeof alp);
			memset(chk, 0, sizeof chk);
			f(j, 0, s[i].size()) {
				if (alp[decode[j] - 'a'] == 0 && !chk[s[i][j] - 'a']) {
					chk[s[i][j] - 'a'] = 1;
					alp[decode[j] - 'a'] = s[i][j];
				}
				else if (alp[decode[j] - 'a'] != s[i][j]) {
					flg = false;
					break;
				}
			}
			if (flg) {
				ok = 1;
				f(j, 0, 26) {
					if (de[j] == 0) {
						de[j] = alp[j];
					}
					else if (de[j] != alp[j]) {
						de[j] = '?';
					}
				}
			}
		}
		f(j, 0, 26) {
			if (de[j] == '?')
				break;
			if (de[j] != 0) {
				cnt++;
				sel[de[j]-'a'] = true;
			}
		}
		if (cnt == 25) {
			char tmp;
			f(i, 0, 26) {
				if (!sel[i])
					tmp = i;
			}
			f(i, 0, 26)
				if (de[i] == 0)
					de[i] = tmp + 'a';
		}
		string ans = "";
		f(i, 0, incode.size()) {
			bool flg = false;
			f(j, 0, 26) {
				if (de[j] == incode[i]) {
					flg = true;
					ans += 'a' + j;
					break;
				}
			}
			if (!flg)
				ans += '?';
		}
		cout << (ok ? ans : "IMPOSSIBLE") << '\n';
	}

	return 0;
}
