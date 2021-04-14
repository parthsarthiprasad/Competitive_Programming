#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int64_t> vec(n);
        rep(i,0,n) cin>>vec[i];
    
    vector<int64_t> numoperations(n,0);
    rep(i,0,n-1){
        numoperations[i] = (vec[i+1]  - vec[i]);

    }
    int64_t count = 0, mincount = 1e18;
    rep(i,0,n){
        count+=abs(numoperations[i]);
    }
    rep(i,0,n){

      
            int64_t tempcount = count - (i-1>=0?abs(numoperations[i-1]):0) - abs(numoperations[i]) + (i+1<n && i-1>=0?abs(vec[i+1] - vec[i-1]):0);
            // cout<<i<<" "<<tempcount<<endl;
            mincount = min(mincount, tempcount);
        
       
        
    }
    // for(auto a:numoperations){
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    cout<<mincount<<endl;
    }
    return 0;
}