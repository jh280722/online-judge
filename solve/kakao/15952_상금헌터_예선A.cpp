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
int one[101]={0,500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10,};
int two[65]={0,512,256,256,128,128,128,128,64,64,64,64,64,64,64,64, 32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,};
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>t;

        while(t--) {
                int a,b,sum;
                cin>>a>>b;
                sum=one[a]+two[b];
                if(sum!=0)
                        cout<<one[a]+two[b]<<"0000"<<'\n';
                else
                        cout<<sum <<'\n';
        }
        return 0;
}
