#include <bits/stdc++.h>
//#include <regex> 정규표현식
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
        // string s; cin>>s; cout<<(regex_match(s,regex("(pi|ka|chu)+")) ? "YES" : "NO");
        string s;
        cin>>s;
        int i=0;
        for(int i = 0; s[i]; i++) {
                if(s[i]=='p'&& s[i+1]=='i') {
                        i++;
                }
                else if(s[i]=='k'&&s[i+1]=='a') {
                        i++;
                }
                else if(s[i]=='c'&&s[i+1]=='h'&&s[i+2]=='u') {
                        i+=2;
                }
                else{
                        cout<<"NO";
                        return 0;
                }
        }
        cout<<"YES";
        return 0;
}
