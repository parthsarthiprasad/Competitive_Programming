#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        rep(i,0,n)cin>>vec[i];
        int64_t sum = 0;
        vector<int64_t> prefixvalues(1 + (n+1)/2,0);
        prefixvalues[1] = max(vec[0], vec[n-1]);
        for(int i=2;i<=(n+1)/2;i++){
            if(i-1 != n-i){
            prefixvalues[i] = max(prefixvalues[i-1] + max(vec[i-1], vec[n-i]),
                         prefixvalues[i-2] + vec[i-1] + vec[n-i]);
            }else{
                prefixvalues[i] = prefixvalues[i-1] + vec[i-1];
            }
        }
        bool possible = false;
        for(auto a: prefixvalues){
            cout<<a<<" ";
            if(a>=k) possible = true;
        }
        if(possible){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        
        
    }
    return 0;
}