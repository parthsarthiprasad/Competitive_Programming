#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int ptr[51][1501];
 int n,k,p;
ll findans(int idx, int p ){
    if(idx>=n) return 0;
    if(p==0) return 0;
    ll ans = 0;
    for(int i=0;i<k;i++){
        if(p-i-1>=0){
        ans = max(ans, ptr[idx][i] + findans(idx+1,p-i-1));
        }
    }
    return ans;
}
int solve(){
   
    cin>>n>>k>>p;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++) cin>>ptr[i][j];
    }
    
    for(int i=0;i<n;i++){
        for(int j=1;j<k;j++) ptr[i][j]+=ptr[i][j-1];
    }
    
    //now we have prefix sums
    return findans(0,p);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i++<<": "<<solve()<<"\n";
    }
    return 0;
}