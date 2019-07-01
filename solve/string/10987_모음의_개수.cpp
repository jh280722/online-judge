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
        string s,a;
        cin>>s;
        for(char t:s) {
                if(t=='a' || t=='e'||t=='i'||t=='o' ||t=='u')
                        cnt++;
        }
        cout<<cnt;
        return 0;
}
