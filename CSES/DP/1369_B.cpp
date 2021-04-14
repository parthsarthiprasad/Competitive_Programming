#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int level;
    cin>>level;
    if(level<3){
        cout<<0<<endl;
        continue;
    }
    int mod = 1e7+9;
    ll ans =0;
    for (int i=level; i >0 ; i-=2){
        (ans +=pow(3,(i-1)/2))%=mod;
    }
    cout<<ans<<endl;
    
    
    }  
return 0;
}