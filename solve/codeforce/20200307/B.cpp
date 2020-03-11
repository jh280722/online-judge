#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n, m, k, a[40005], b[40005], sa[40005], sb[40005];
vector <pair<int, int>> p;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sa[i] = sa[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        sb[i] = sb[i - 1] + b[i];
    }
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            p.push_back({ i,k / i });
            if (i * i != k) p.push_back({ k / i,i });
        }
    }
    ll ans = 0;
    for (auto l : p) {
        ll ca = 0, cb = 0;
        for (int i = l.first; i <= n; i++) {
            if (sa[i] - sa[i - l.first] == l.first) ca++;
        }
        for (int i = l.second; i <= m; i++) {
            if (sb[i] - sb[i - l.second] == l.second) cb++;
        }
        ans += ca * cb;
    }
    cout << ans;
}