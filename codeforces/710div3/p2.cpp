#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
       string s;
       cin>>s;
       int start = n;
       int end =  -1;
       for(int i=0;i<s.size();i++){
           if(s[i]=='*'){
           start = min(start,i);
           end = max(end,i);
           }
       }
       int sumval = 1;
       int prevval = start;
       s[start]='H';
       for(int i=start+1;i<s.size();i++){
           if(i-start>k){
               if(s[prevval]!='H'){
               s[prevval] = 'H';
               start = prevval;
               sumval++;
               }
           }
           if(s[i]=='*'){
               prevval=i;
           }
       }
    //    cout<<s<<endl;
       if(s[end]=='*') sumval++;
       cout<<sumval<<endl;
    }
}