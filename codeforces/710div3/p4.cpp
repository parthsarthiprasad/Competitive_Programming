#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            mp[val]++;
        }
        // for(auto a:mp){cout<<a.second<<" ";}
        // cout<<endl;
        if(mp.size()==1){
            // cout<<"HELLO ";
            cout<<n<<endl;
        }else if(mp.size()==2){
            int val1 = (*mp.begin()).second;
            mp.erase(mp.begin());
            int val2 = (*mp.begin()).second;
            cout<<abs(val1- val2)<<endl;
        }else{
            int maxval = 0;
            for(auto a:mp){
                maxval = max(maxval,a.second);
            }
            if(maxval>n/2){
                cout<<maxval-(n-maxval)<<endl;
            }
            else cout<<(n%2)<<endl;
        }
    }
}