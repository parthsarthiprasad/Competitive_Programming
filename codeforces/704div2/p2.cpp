#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;;
        map<char,int> mp;
        for(auto a:s){
            mp[a]++;
        }
        // for(auto a:mp){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        int unique = 0;
        int even = 0;
        for(auto a:mp){
            if(a.second==1){
                unique++;
            }
            else if(a.second&1){
                 even+=(a.second-3)/2;
            }else{
                 even+=a.second/2;
            }
           
                even+=a.second/2;

            
        }
        // cout<<even<<" "<<unique<<endl;
        if(even-unique<0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}