#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
bool ch=false;
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
        cin>>n;
        memset(a1,-1,sizeof(a1));
        for(int i=0; i<n; i++) {
                int eff,name;
                cin>>eff>>name;
                a1[eff]=name;
        }
        cin>>t;
        while(t--) {
                int r;
                cin>>r;
                ch=false;
                vector<int> v(r);
                for(int i=0; i<r; i++) {
                        int eff;
                        cin>>eff;
                        if(a1[eff]!=-1) {
                                v[i]=a1[eff];
                        }
                        else{
                                ch=true;
                        }
                }
                if(ch)
                        cout<<"YOU DIED\n";
                else{
                        for(auto i:v) {
                                cout<<i<<' ';
                        }
                        cout<<'\n';
                }
        }
        return 0;
}
