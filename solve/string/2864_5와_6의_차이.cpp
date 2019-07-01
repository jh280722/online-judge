#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool ch1[101];
bool ch2[101][101];
int a[301][301];
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
int n, m;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string a,b;
        cin>>a>>b;
        string maxa=a,maxb=b;
        string mina=a,minb=b;
        for(int i=0; i<a.length(); i++) {
                if(a[i]=='6')
                        mina[i]='5';
                else if(a[i]=='5')
                        maxa[i]='6';
        }
        for(int i=0; i<a.length(); i++) {
                if(b[i]=='6')
                        minb[i]='5';
                else if(b[i]=='5')
                        maxb[i]='6';
        }
        int min,max;
        min=atoi(mina.c_str())+atoi(minb.c_str());
        max=atoi(maxa.c_str())+atoi(maxb.c_str());
        cout<<min<<' '<<max;
        return 0;
}
