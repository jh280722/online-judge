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
        string s="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec quis lectus sit amet ante suscipit tempor. Aenean dapibus finibus tortor vitae facilisis. Nulla facilisi. Donec suscipit ante a sapien gravida eleifend. Curabitur in lectus ut enim semper venenatis. Aenean elit nibh, hendrerit nec nunc in, dictum cursus dolor. Aenean eget lectus risus. Cras sollicitudin quam vitae augue mollis bibendum. Aliquam euismod vulputate dolor at tristique. Praesent elementum pretium velit non interdum. Nunc posuere faucibus magna id pretium. Maecenas congue, velit eget semper porttitor, tellus tortor porttitor dui, tristique lobortis quam sem ac odio.";
        stringstream sm(s);
        vector<string> ss;
        string t;
        while (sm >> t) ss.push_back(t);
        int a,b;
        cin>>a>>b;
        for(int i=a; i<=b; i++) {
                cout<<ss[i-1]<<' ';
        }

        return 0;
}
