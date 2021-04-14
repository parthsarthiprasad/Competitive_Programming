#include<bits/stdc++.h>
using namespace std;
struct dec{
    int val;
    map<int,int> mp;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        vector<dec> gm;
        for(int i=0;i<n;i++){
            int temp = vec[i];
            for(int j=2;j*j<=temp && temp>1;j++){
                while(temp%j==0){
                    gm[i].val = vec[i];
                    gm[i].mp[j]++;
                    temp/=j;
                }
            }
        }
        int zeroanswer = 0;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                map<int,int> kc;
                for(auto a:gm[i].mp){
                    kc[a.first]+=a.second;
                }
                for(auto a:gm[j].mp){
                    kc[a.first]+=a.second;
                }
                int count = 0;
                for(auto a:kc){
                    if(a.second&1)count++;
                }
                if(count==0){
                   ans[i]++;
                   ans[j]++;
                }
            }
        }
        zeroanswer = *max_element(ans.begin(),ans.end());
        int finasnwer = 0;
        ans = vector<int>(n,1);
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                map<int,int> kc;
                for(auto a:gm[i].mp){
                    kc[a.first]+=a.second;
                }
                for(auto a:gm[j].mp){
                    kc[a.first]+=a.second;
                }
                int count = 0;
                for(auto a:kc){
                    if(a.second&1)count++;
                }
                if(count<=1){
                   ans[i]++;
                   ans[j]++;
                }
            }
        }
        finasnwer = *max_element(ans.begin(),ans.end());
        int q;
        cin>>q;
        while(q--){
            int t;
            cin>>t;
            if(t==0) cout<<zeroanswer<<endl;
            else cout<<finasnwer<<endl;
        }


        
    }
    return 0;
}