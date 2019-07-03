#include <iostream>
using namespace std;
int a[26];
bool ok;
int main()
{
        int n;
        char s[31];
        cin>>n;
        while(n--) {
                cin>>s;
                a[s[0]-'a']++;
        }
        for(int i=0; i<26; i++)
                if(a[i] >= 5)
                        ok = true, cout<<char(i+'a');
        if(!ok) cout<<"PREDAJA";

        return 0;
}
