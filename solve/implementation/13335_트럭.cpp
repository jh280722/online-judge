#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct point {
        int x, y;
        point(int x, int y) {
                this->x = x;
                this->y = y;
        }
        point() {
        }
};
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n,w,l;
        cin>>n>>w>>l;
        std::vector<int> v(n);
        queue<point> q;
        for(int i=0; i<n; i++) {
                cin>>v[i];
        }
        int cnt=1,remainl=l-v[0];
        int now=0;
        bool ch=false;
        q.push({v[0],w});
        while(!q.empty()) {
                int s=q.size();
                ch=false;
                while(s--) {
                        int nl=q.front().x;
                        int nw=q.front().y;
                        q.pop();
                        if( nw>0) {
                                nw--;
                                if(nw==0)
                                        remainl+=nl;
                                else
                                        q.push({nl,nw});
                        }
                        if(!ch && now +1 <n && remainl-v[now+1]>=0) {
                                ch=true;
                                remainl-=v[++now];
                                q.push({v[now],w});
                        }
                }
                cnt++;
        }
        cout<<cnt;
        return 0;
}

// #include <iostream>
// int main()
// {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int n, w, L;
//         int A[1000] = { 0 };
//         int B[100] = { 0 };
//         int num = 0;
//         int time = 0;
//         cin>>n>>w>>L;
//         for (int i = 0; i < n; i++)
//         {
//                 cin>>A[i];
//         }
//         while (num < n)
//         {
//                 int count = 0;
//                 for (int i = w - 1; i > 0; i--)
//                 {
//                         B[i] = B[i - 1];
//                         count += B[i];
//                 }
//                 count += A[num];
//                 if (count > L)
//                         B[0] = 0;
//                 else
//                 {
//                         B[0] = A[num];
//                         num++;
//                 }
//                 time++;
//         }
//         time += w;
//         cout<<time;
// }
