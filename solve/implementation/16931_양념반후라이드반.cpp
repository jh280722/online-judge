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
int n, m, l,ans;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        if(a+b>2*c) {
                int z=min(x,y);
                ans=z*c*2;
                if(a>2*c && b>2*c) {
                        ans+=(x-z)*2*c;
                        ans+=(y-z)*2*c;
                }
                else if(a>2*c && b<=2*c) {
                        ans+=(x-z)*2*c;
                        ans+=(y-z)*b;
                }
                else if(a<=2*c && b>2*c) {
                        ans+=(x-z)*a;
                        ans+=(y-z)*2*c;
                }
                else{
                        ans+=(x-z)*a;
                        ans+=(y-z)*b;
                }
        }
        else{
                ans=x*a;
                ans+=y*b;
        }
        cout<<ans;
        return 0;
}
