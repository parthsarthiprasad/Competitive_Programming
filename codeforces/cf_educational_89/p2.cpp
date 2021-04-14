#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int solve(){
    int n,x,m;
    cin>>n>>x>>m;
    int lbound = x;
    int rbound =x;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        //check if they fall in region
        if(rbound<a || lbound>b)
        continue;
        lbound = min(lbound,a);
        rbound = max(rbound,b);
        // if(lbound<b ){
        //     if(lbound>a)
        //         lbound=a;
        //     else{
        //         if(rbound<a)
        //          continue;
        //         else
        //          rbound = max(rbound,b);
        //     }
        // }
        //  if(rbound>a ){
        //     if(rbound>a)
        //         lbound=a;
        //     else{
        //         if(rbound<a)
        //          continue;
        //         else
        //          rbound = max(rbound,b);
        //     }
        // }
    }
    return rbound-lbound+1;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       cout<<solve()<<endl;
    }
    return 0;
}