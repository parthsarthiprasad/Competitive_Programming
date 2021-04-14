#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int x,y,k,n;
       cin>>x>>y>>k>>n;
       if(abs(x-y)%k==0){
           if((abs(x-y)/k)&1)cout<<"No\n";
           else cout<<"Yes\n";
       }else{
           cout<<"No\n";
       }
    }
    return 0;
}