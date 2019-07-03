#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool ch1[101];
bool ch2[101][101];
int a1[101];
int a2[301][301];
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
        cin>>n>>k;
        vector<tuple<int,int,int> > ct(n);
        for(int i=0; i<n; i++) {
                int g,s,b;
                cin>>m>>g>>s>>b;
                ct[m-1]=make_tuple(g,s,b);
        }
        cnt=1;
        for(int i=0; i<n; i++) {
                if(i==k-1)
                        continue;
                if(get<0>(ct[k-1])<get<0>(ct[i]))
                        cnt++;
                else if(get<0>(ct[k-1])==get<0>(ct[i]) && get<1>(ct[k-1])<get<1>(ct[i])) {
                        cnt++;
                }
                else if(get<0>(ct[k-1])==get<0>(ct[i]) && get<1>(ct[k-1])==get<1>(ct[i]) && get<2>(ct[k-1])<get<2>(ct[i])) {
                        cnt++;
                }
        }
        cout<<cnt;
        return 0;
}
