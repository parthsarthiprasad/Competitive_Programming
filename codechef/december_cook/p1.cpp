#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n;
       string s;
       cin>>s;
       int count = 0;
       for(int i=0;i<n;i++){
           count+= (s[i]=='0');
       }
       if(count>30)cout<<"NO\n";
       else cout<<"YES\n";
    }
    return 0;
}