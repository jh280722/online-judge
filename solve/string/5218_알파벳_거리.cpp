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
        cin>>t;
        while(t--) {
                string a,b;
                cin>>a>>b;
                cout<<"Distances: ";
                for(int i=0; i<a.length(); i++) {
                        int d=b[i]-a[i];
                        if(d<0)
                                d+=26;
                        cout<<d<<' ';
                }
        }
        return 0;
}
