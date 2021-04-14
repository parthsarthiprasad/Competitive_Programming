#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){cin>>vec[i];}
        // map<int,vector<int> > mp;
        vector<vector<int>> vt(21);
        // for(int i=0;i<n;i++){
        //     bool done = true;
        //     for(int64_t j=20;j>=0 && !done;j--){
        //     cout<<(vec[i] & (1<<j))<<endl;

        //         if((vec[i] & (1ll<<j))!=0){
        //             cout<<vec[i]<<" "<<j<<endl;
        //             vt[j].push_back(vec[i]);
        //             done = true;
        //         }
                
        //     }
        // }
        for(auto a:vec){
            bool done = true;
            for(int j=20;j>=0 && done;j--){
            // cout<<j<<" "<<(a & (1<<j))<<endl;

                if((a & (1ll<<j))!=0){
                    // cout<<a<<" "<<j<<endl;
                    vt[j].push_back(a);
                    done = false;
                }
                
            }
        }

        // cout<<endl;
        int64_t sum = 0;
        int64_t prefix = (1ll<<21)-1;
        // for(auto a:vt){
        //     cout<<a.size();
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i=20;i>=0;i--){
            sort(vt[i].rbegin(), vt[i].rend());
            // if(vt[i].size()!=0)cout<<i<<"   ";
            // for(auto a:mp[i]){
            //     cout<<a<<" ";
            // }
            // cout<<endl;
            for(auto a:vt[i]){
                prefix=  prefix & a;
                // cout<<prefix<<" ";
                sum+=prefix;
            }
        }
        cout<<sum<<endl;
    }
}