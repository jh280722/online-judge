#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool ch1[101];
bool ch2[101][101];
int a1[101];
int a2[500][500];
ll cnt = 0;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
struct point {
        int x, y;
        point(int x, int y) {
                this->x = x;
                this->y = y;
        }
        point() {
        }
};
int t;
int n, m, k;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>n>>m;
        for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                        cin>>a2[i][j];
                }
        }
        vector<int> r(n),c(m);
        for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                        string s=to_string(a2[i][j]);
                        for(char v:s) {
                                if(v=='9') {
                                        r[i]++;
                                        c[j]++;
                                }
                        }
                }
        }
        int rmax=*max_element(r.begin(),r.end());
        int cmax=*max_element(c.begin(),c.end());
        int rcmax=max(rmax, cmax);
        cout<<accumulate(r.begin(), r.end(), 0)-rcmax;
        return 0;
}
