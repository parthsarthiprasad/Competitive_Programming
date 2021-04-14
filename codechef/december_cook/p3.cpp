#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       int count =0;
       for(int i=0;i<(int)s.size();i++){
           if(s[i]=='1')count++;
           else count--;
       }
       count = abs(count);
       if(count==0 || count == (int)s.size() || count == -(int)s.size())cout<<-1<<"\n";
       else cout<<(count/2)<<"\n";
    }
    return 0;
}