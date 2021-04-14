#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int64_t n;
        cin>>n;
        map<int64_t,int> mp;
        for(int64_t i=2;i*i<=n;i++){
            while(n%i==0){
                mp[i]++;
                n/=i;
            }
        }
        if(n!=1){
            mp[n]++;
            n=1;
        }
        vector<int64_t> ans;
        // for(auto a:mp){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        for(auto a:mp){
            for(int i=0;i<a.second;i++){
                if(i>=ans.size()){
                    ans.push_back(a.first);
                }else{
                    ans[i]*=a.first;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(auto a:ans){
            cout<<a<<" ";
        }
        cout<<endl;

    }
}