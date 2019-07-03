#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <set>
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
        string s,a;
        double g,gpa=0;
        cin>>t;
        while(t--) {
                cin>>s>>n>>a;
                if(a[0]=='F')
                        g=0.0;
                else{
                        g='D'-a[0]+1;
                        if(a[1]=='+')
                                g+=0.3;
                        else if(a[1]=='-') {
                                g-=0.3;
                        }
                }
                cnt+=n;
                gpa+=g*n;
        }
        gpa/=cnt;
        cout<<fixed<<setprecision(2)<<gpa+0.0001;
        return 0;
}
