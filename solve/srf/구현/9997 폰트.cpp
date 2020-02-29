#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, ans;
int check[26];

void DFS(int cnt, int value) {
    if (cnt == n - 1) {
        if (value == (1<<26) -1)
            ans++;
        return;
    }
    DFS(cnt + 1, value | check[cnt + 1]);
    DFS(cnt + 1, value);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            check[i] |= 1<< (s[j] - 'a');
        }
    }
    DFS(-1, 0);
    cout << ans;
    return 0;
}
